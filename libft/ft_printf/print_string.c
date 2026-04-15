/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:04:40 by abuet             #+#    #+#             */
/*   Updated: 2026/02/17 13:32:45 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_str(va_list arg)
{
	char	*c;
	int		i;

	i = 0;
	c = va_arg(arg, char *);
	if (!c)
		return (write (1, "(null)", 6));
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
	return (i);
}

int	ft_char(va_list arg)
{
	char	c;

	c = va_arg(arg, int);
	ft_putchar(c);
	return (1);
}
