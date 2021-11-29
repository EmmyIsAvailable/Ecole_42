#include "printf.h"

int	ft_which_char(const char c, va_list args, int j)
{	
	if (c == 'c')
		return (ft_print_c(args, j));
	if (c == 's')
		return (ft_print_str(args, j));
	if (c == 'p')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == 'd' || c == 'i')
		return (ft_print_nb(args, j));
	if (c == 'u')
		return (ft_print_unsigned_nb(args, j));
	if (c == '%')
		return (ft_print_percent());
	return (0);
}

int	ft_go_through_format(const char *format, va_list args)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = 0;
	j = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '%')
				j++;
			len += ft_which_char(format[i], args, j);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_go_through_format(format, args);
	va_end(args);
	return (len);
}