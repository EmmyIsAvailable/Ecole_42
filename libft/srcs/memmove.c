#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cast_dest;
	unsigned char	*cast_src;
	unsigned char	*temp;
	
	i = 0;
	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	temp[n] = 0;
	while (i < n)
	{
		temp[i] = cast_src[i];
		cast_dest[i] = temp[i];
		i++;
	}
	return (dest);
}