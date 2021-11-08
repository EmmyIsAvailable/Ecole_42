#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*cast_dest;
	char	*cast_src;
	char	*temp;
	
	i = 0;
	cast_dest = (char *)dest;
	cast_src = (char *)src;
	temp[n] = 0;
	while (i < n)
	{
		temp[i] = cast_src[i];
		cast_dest[i] = temp[i];
		i++;
	}
	return (cast_dest);
}