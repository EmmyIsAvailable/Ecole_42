#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*sub;
	unsigned int	i;
	
	i = -1;
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (++i < len && s[start + i])
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}