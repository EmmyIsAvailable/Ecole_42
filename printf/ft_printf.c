/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:56:38 by eruellan          #+#    #+#             */
/*   Updated: 2021/12/01 11:51:28 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_which_char(const char c, va_list args)
{
	if (c == 'c')
		return (ft_print_c(va_arg(args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long int)));
	if (c == 'x')
		return (ft_printx(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_printx(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == 'd' || c == 'i')
		return (ft_print_nb(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_unsigned_nb(va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_print_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_which_char(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
