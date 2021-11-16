#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*join;
	int		i;
	int		j;
	
	i = -1;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc(sizeof(char) * len);
	if (!join)
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	while (s2[++j])
		join[i+j] = s2[j];
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

int	prochain_n(char *a_lire)
{
	int	i;
	
	i = -1;
	while (a_lire[++i])
		if (a_lire[i] == '\n')
			return (0);
	return (1);
}