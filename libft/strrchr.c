#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*cast_s;
	
	i = ft_strlen(s);
	cast_s = (char *)s;
	if (c == '\0')
		return ("\0");
	while (cast_s[--i])
	{
		if (cast_s[i] == c)
			return (&cast_s[i]);
	}
	return (NULL);
}