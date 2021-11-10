#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		length;
	int		i;
	
	length = ft_strlen(s);
	i = -1;
	new = (char *)malloc(sizeof(char) * (length + 1));
	if (!new)
		return (NULL);
	while (++i < length)
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}