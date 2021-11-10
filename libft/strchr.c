#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	char	*cast_s;
	
	i = 0;
	cast_s = (char *)s;
	if (c == '\0')
		return ("\0");
	while (cast_s[i])
	{
		if (cast_s[i] == c)
			return (&cast_s[i]);
		i++;
	}
	return (NULL);
}