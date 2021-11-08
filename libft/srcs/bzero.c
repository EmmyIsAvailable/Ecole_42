#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t 			i;
	unsigned char	*cast_s;
	
	i = 0;
	cast_s = (unsigned char *)s;
	while (i < n)
	{
		cast_s[i] = 0;
		i++;
	}
}