#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	
	i = ft_strlen(src);
	j = 0;
	if(size == 0)
		return (i);
	while(src[j] && j < size - 1)
	{	
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return(i);
}