#include "printf.h"

int	ft_print_c(va_list args, int j)
{
	int	curr_arg;

	while (j--)
		curr_arg = va_arg(args, int);
	ft_putchar_fd(curr_arg, 1);
	return (1);
}

int	ft_print_str(va_list args, int j)
{
	char	*curr_arg;

	while (j--)
		curr_arg = va_arg(args, char *);
	ft_putstr_fd(curr_arg, 1);
	return (ft_strlen(curr_arg));
}

int	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	ft_print_nb(va_list args, int j)
{
	int 	curr_arg;
	char	*nb;

	while (j--)
		curr_arg = va_arg(args, int);
	nb = ft_itoa(curr_arg);
	ft_putstr_fd(nb, 1);
	free(nb);
	return (ft_strlen(nb));
}

int	ft_print_unsigned_nb(va_list args, int j)
{
	unsigned int 	curr_arg;
	char			*nb;

	while (j--)
		curr_arg = va_arg(args, unsigned int);
	nb = ft_itoa(curr_arg);
	ft_putstr_fd(nb, 1);
	free(nb);
	return (ft_strlen(nb));
}