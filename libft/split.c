#include <stdlib.h>

int	nb_words(char const *s, char c)
{
	int	i;
	int	count;
	int	len;
	
	i = 0;
	count = 0;
	while (s[i])
	{
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len)
			count++;
		else
			len = 1;
		i += len;
	}
	return (count);
}

char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;
	
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**fill_words(char **res, char const *s, char c)
{
	int	i;
	int	len;
	int	j;
	
	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len)
		{
			res[j] = (char *)malloc(sizeof(char) * (len + 1));
			if (!res[j])
				return (NULL);
			ft_strncpy(res[j], &s[i], len);
			j++;
		}
		else
			len = 1;
		i += len;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int	words;
	
	words = nb_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	fill_words(split, s, c);
	split[words + 1] = NULL;
	return (split);
}