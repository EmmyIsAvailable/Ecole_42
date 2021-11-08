#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*cast_s1;
	char	*cast_s2;
	size_t	i;
	
	cast_s1 = (char *)s1;
	cast_s2 = (char *)s2;
	i = 0;
	while (cast_s1[i] && cast_s2[i] && cast_s1[i] == cast_s2[i] && i < n)
		i++;
	return (cast_s1[i] - cast_s2[i]);
}