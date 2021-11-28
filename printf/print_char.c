#include "printf.h"

int	ft_print_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}