/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:05:47 by eruellan          #+#    #+#             */
/*   Updated: 2021/12/01 11:11:11 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_c(int c);
int	ft_print_str(char *str);
int	ft_print_percent(void);
int	ft_print_nb(int nbr);
int	ft_print_unsigned_nb(unsigned int nbr);
int	ft_print_hex(unsigned long int nbr, char *base);
int	ft_print_ptr(unsigned long int ptr);
int	ft_printx(unsigned int nbr, char *base);

#endif
