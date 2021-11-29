#ifndef __PRINTF_H__
# define __PRINTF_H__

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_c(va_list args, int j);
int	ft_print_str(va_list args, int j);
int	ft_print_percent(void);
int	ft_print_nb(va_list args, int j);
int	ft_print_unsigned_nb(va_list args, int j);

#endif