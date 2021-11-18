#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*join;
	int		i;
	int		j;
	
	i = -1;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc(sizeof(char) * len);
	if (!join)
		return (NULL);
	if (s1)
		while (s1[++i])
			join[i] = s1[i];
	while (s2[j])
	{
		join[i+j] = s2[j];
		j++;
	}
	join[i+j] = '\0';
	return (join);
}

size_t	ft_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*str)
{
	char	*dup;
	int		i;
	
	i = -1;
	dup = (char *)malloc(sizeof(char)*(ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	while (str[++i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

int	prochain_n(char *to_read)
{
	int	i;
	
	i = -1;
	if (!to_read)
		return (0);
	while (to_read[++i])
		if (to_read[i] == '\n')
			return (1);
	return (0);
}