#ifndef __PRINTF_H__
# define __PRINTF_H__

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_c(int c);
int	ft_print_str(char *str);

#endif