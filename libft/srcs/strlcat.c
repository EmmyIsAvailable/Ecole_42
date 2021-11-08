#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if(size - len_dst - 1 < 0)
		return(size + len_src);
	while(src[i] && len_dst + i < size - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return(len_dst + len_src);
}