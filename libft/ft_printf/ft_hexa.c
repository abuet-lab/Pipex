/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:26:27 by abuet             #+#    #+#             */
/*   Updated: 2025/11/08 17:41:16 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_number(unsigned int n)
{
	int	i;

	i = 0;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}

static void	ft_putnbr_hexa(unsigned int n, char c)
{
	static char	lower [] = "0123456789abcdef";
	static char	upper [] = "0123456789ABCDEF";

	if (n >= 16)
		ft_putnbr_hexa(n / 16, c);
	if (c == 'X')
		write(1, &upper[n % 16], 1);
	else
		write(1, &lower[n % 16], 1);
}

int	ft_hexa(va_list arg, char c)
{
	int	n;

	n = va_arg(arg, int);
	ft_putnbr_hexa(n, c);
	return (count_number(n));
}
