#include <stdlib.h>

int	len_chaine(const char *s)
{
	int	i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	len_s1;
	int	len_s2;
	char	*join;
	int	i;
	
	len_s1 = len_chaine(s1);
	len_s2 = len_chaine(s2);
	i = -1;
	join = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!join)
		return (NULL);
	while (++i < len_s1)
		join[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		join[len_s1 + i] = s2[i];
	join[len_s1 + len_s2] = '\0';
	return (join);
}