/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:28:24 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/05/12 14:39:02 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(s_pipex *p, char **envp)
{
	char	*path;

	dup2(p->infile, STDIN_FILENO);
	dup2(p->fd[1], STDOUT_FILENO);
	close(p->fd[0]);
	path = find_path(p->cmd1[0], envp);
	if (!path)
	{
		perror(p->cmd1[0]);
		exit(127);
	}
	execve(path, p->cmd1, envp);
	free(path);
	perror(p->cmd1[0]);
	exit(127);
}


void	parent_process(s_pipex *p, char **envp)
{
	char	*path;

	dup2(p->fd[0], STDIN_FILENO);
	dup2(p->outfile, STDOUT_FILENO);
	close(p->fd[1]);
	waitpid(-1, NULL, 0);
	path = find_path(p->cmd2[0], envp);
	if (!path)
	{
		perror(p->cmd2[0]);
		exit(127);
	}
	execve(path, p->cmd2, envp);
	free(path);
	perror(p->cmd2[0]);
	exit(127);
}

int	main(int argc, char **argv, char **envp)
{
	s_pipex	p;
	pid_t	pid;

	if (argc != 5)
		return (ft_printf("Usage :./pipex infile cmd1 cmd2 outfile\n"), 0);
	p.cmd1 = ft_split(argv[2], ' ');
	p.cmd2 = ft_split(argv[3], ' ');
	p.infile = open(argv[1], O_RDONLY);
	if (p.infile == -1)
		perror(argv[1]);
	p.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p.outfile == -1)
		perror(argv[4]);
	pipe(p.fd);
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
		child_process(&p, envp);
	else
		parent_process(&p, envp);
}
