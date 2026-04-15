/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigndeci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:29:36 by abuet             #+#    #+#             */
/*   Updated: 2025/11/08 17:40:55 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_number(unsigned int c)
{
	unsigned int	i;

	i = 0;
	while (c >= 10)
	{
		c /= 10;
		i++;
	}
	return (i + 1);
}

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

static void	ft_putnbr(unsigned int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

int	ft_unsigndeci(va_list arg)
{
	unsigned int	n;

	n = va_arg(arg, unsigned int);
	ft_putnbr(n);
	return (count_number(n));
}
