#include "printf.h"

int	ft_which_char(const char c, va_list args)
{
	if (c == 'c')
		return (ft_print_c(va_arg(args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (c == 'p')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == 'd')
		return (1);
	if (c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(args, format);
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