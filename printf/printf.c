#include "printf.h"
#include <stdio.h>
void	ft_printf(char *format, ...)
{
	va_list	args;
	char	*curr_arg;
	
	curr_arg = format;
	va_start(args, format);
	while (curr_arg)
	{
		printf("%s\n", curr_arg);
		curr_arg = va_arg(args, char *);
	}
	va_end(args);
}