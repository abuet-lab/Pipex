/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:05:46 by abuet             #+#    #+#             */
/*   Updated: 2025/11/08 17:57:00 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_tri(const char *str, int i, va_list arg)
{
	int	count;

	count = 0;
	if (str[i] == 's')
		count = ft_str(arg);
	else if (str[i] == 'c')
		count = ft_char(arg);
	else if (str[i] == 'p')
		count = ft_ptr(arg);
	else if (str[i] == 'd' || str[i] == 'i')
		count = ft_deci(arg);
	else if (str[i] == 'x' || str[i] == 'X')
		count = ft_hexa(arg, str[i]);
	else if (str[i] == 'u')
		count = ft_unsigndeci(arg);
	else if (str[i] == '%')
	{
		write(1, "%", 1);
		count = 1;
	}
	else
		return (0);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	va_start(arg, str);
	if (!str)
		return (write (1, "(null)", 6));
	while (str[i])
	{
		if (str[i] == '%')
		{
			counter += ft_tri(str, i + 1, arg);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			counter++;
		}
		i++;
	}
	va_end(arg);
	return (counter);
}
