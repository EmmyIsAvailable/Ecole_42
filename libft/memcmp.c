#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;
	size_t			i;
	
	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	i = 0;
	if (!s1 && !s2)
		return (0);
	while (cast_s1[i] && cast_s2[i] && cast_s1[i] == cast_s2[i] && i < n)
		i++;
	return (cast_s1[i] - cast_s2[i]);
}