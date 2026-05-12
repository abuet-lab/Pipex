/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:29:33 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/05/12 14:40:01 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct t_pipex
{
	int infile;
	int outfile;
	char **cmd1;
	char **cmd2;
	int fd[2];
} s_pipex;

char	*find_path(char *cmd, char **envp);

#endif