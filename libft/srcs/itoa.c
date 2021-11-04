#include <libft.h>

int	nb_digits(int n)
{
	int	digits;
	
	digits = 0;
	if (n < 0)
	{
		n *= (-1);
		digits++;
	}
	while (n > 9)
	{
		n = n / 10;
		digits++;
	}
	return (digits + 1);
}

char	*fill_numbers(int n, char *tofill, int len)
{
	if (n > 9)
		fill_numbers((n / 10), tofill, (len - 1));
	tofill[len - 1] = n % 10 + 48;
	return (tofill);
}

char	*ft_itoa(int n)
{
	char	*number;
	int	digits;
	
	digits = nb_digits(n);
	number = (char *)malloc(sizeof(char) * (digits + 1));
	if (!number)
		return (NULL);
	if (n < 0)
	{
		number[0] = '-';
		n *= (-1);
	}
	fill_numbers(n, number, digits);
	number[digits] = '\0';
	return (number);
}