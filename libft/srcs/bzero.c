#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;
	char	*cast_s;
	
	i = 0;
	cast_s = (char *)s;
	while (cast_s[i] && i < n)
	{
		cast_s[i] = '\0';
		i++;
	}
}