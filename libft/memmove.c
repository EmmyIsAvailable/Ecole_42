#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cast_dest;
	unsigned char	*cast_src;
	
	i = -1;
	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (cast_src > cast_dest)
	{	
		while (++i < n)
			cast_dest[i] = cast_src[i];
	}
	else 
	{
		while (n-- > 0)
			cast_dest[n - 1] = cast_src[n - 1];
	}
	return (cast_dest);
}