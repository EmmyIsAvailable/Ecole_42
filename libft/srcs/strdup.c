#include <stdlib.h>

char	*ft_strdup(char *s)
{
	char	*new;
	int	length;
	int	i;
	
	length = 0;
	i = 0;
	while (s[length])
		length++;
	new = malloc(sizeof(char) * (length + 1));
	if (!new)
		return (NULL);
	while (i < length)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}