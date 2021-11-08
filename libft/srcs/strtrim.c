#include "libft.h"

static int	is_in_charset(char c, char const *set)
{
	int	i;
	
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	nb_total(char const *s1, char const *set)
{
	int	i;
	int len;
	
	i = 0;
	len = 0;
	while (s1[len])
		len++;
	while (s1[len--] && is_in_charset(s1[len], set));
	while (s1[i++] && is_in_charset(s1[i], set))
		len--;
	return (len);
}

static char	*fill_str(char *str, char const *s1, char const *set)
{
	int	i;
	int	j;
	int	len;
	
	i = -1;
	j = 0;
	len = nb_total(s1, set);
	while (s1[++i] && is_in_charset(s1[i], set));
	while (s1[i] && !is_in_charset(s1[i], set))
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;
	char	*str_trimmed;
	
	len = nb_total(s1, set);
	str_trimmed = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_trimmed)
		return (NULL);
	fill_str(str_trimmed, s1, set);
	return (str_trimmed);
}