/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:53:47 by abuet             #+#    #+#             */
/*   Updated: 2025/11/08 17:41:07 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static long	count_number(uintptr_t n)
{
	long	i;

	i = 0;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}

static void	ft_putnbr_hex(uintptr_t n)
{
	static char	hexa[] = "0123456789abcdef";

	if (n >= 16)
		ft_putnbr_hex(n / 16);
	write(1, &hexa[n % 16], 1);
}

int	ft_ptr(va_list arg)
{
	void	*p;

	p = va_arg(arg, void *);
	if (p == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	ft_putnbr_hex((uintptr_t) p);
	return (count_number((uintptr_t) p) + 2);
}
