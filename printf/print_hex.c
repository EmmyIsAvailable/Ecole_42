/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:56:26 by eruellan          #+#    #+#             */
/*   Updated: 2021/12/01 11:22:05 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long int nbr, char *base)
{
	int	len;

	len = 1;
	if (nbr >= 16)
		len += ft_print_hex(nbr / 16, base);
	ft_putchar_fd(base[nbr % 16], 1);
	return (len);
}

int	ft_print_ptr(unsigned long int ptr)
{
	int	len;

	len = 2;
	ft_putstr_fd("0x", 1);
	len += ft_print_hex(ptr, "0123456789abcdef");
	return (len);
}

int	ft_printx(unsigned int nbr, char *base)
{
	int	len;

	len = 1;
	if (nbr >= 16)
		len += ft_printx(nbr / 16, base);
	ft_putchar_fd(base[nbr % 16], 1);
	return (len);
}
