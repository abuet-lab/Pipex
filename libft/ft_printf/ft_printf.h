/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:57:50 by abuet             #+#    #+#             */
/*   Updated: 2025/11/08 17:33:47 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_str(va_list arg);
int	ft_char(va_list arg);
int	ft_deci(va_list arg);
int	ft_hexa(va_list arg, char c);
int	ft_ptr(va_list arg);
int	ft_unsigndeci(va_list arg);

#endif
