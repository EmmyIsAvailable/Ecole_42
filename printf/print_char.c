/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:56:30 by eruellan          #+#    #+#             */
/*   Updated: 2021/12/01 11:20:16 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	ft_print_nb(int nbr)
{
	int	len;

	len = 1;
	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
	}
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr *= -1;
		len++;
	}
	if (nbr >= 10)
		len += ft_print_nb(nbr / 10);
	ft_putchar_fd(nbr % 10 + 48, 1);
	return (len);
}

int	ft_print_unsigned_nb(unsigned int nbr)
{
	int	len;

	len = 1;
	if (nbr >= 10)
		len += ft_print_nb(nbr / 10);
	ft_putchar_fd(nbr % 10 + 48, 1);
	return (len);
}
