#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*cast_s;
	size_t	i;
	
	cast_s = (unsigned char *)s;
	i = 0;
	while (cast_s[i] && i < n)
	{
		if (cast_s[i] == c)
			return (&cast_s[i]);
		i++;
	}
	return (0);
}