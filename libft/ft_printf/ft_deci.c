/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deci.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:49:26 by abuet             #+#    #+#             */
/*   Updated: 2025/11/08 17:41:21 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_number(int c)
{
	int	i;

	i = 0;
	if (c == -2147483648)
		return (11);
	if (c < 0)
	{
		c *= -1;
		i += 1;
	}
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

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
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

int	ft_deci(va_list arg)
{
	int	n;

	n = va_arg(arg, int);
	ft_putnbr(n);
	return (count_number(n));
}
