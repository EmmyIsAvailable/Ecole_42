#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*new;
	unsigned int	i;
	
	i = -1;
	len = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (++i < len)
		new[i] = (char)f(i, s[i]);
	new[i] = '\0';
	return (new);
}