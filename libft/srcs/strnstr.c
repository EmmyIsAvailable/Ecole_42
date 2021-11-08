#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int	i;
	size_t	j;
	
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i+j] && s2[j] && s1[i + j] == s2[j] && j < n)
			j++;
		if (s2[j] == '\0')
			return (&s1[i]);
		i++;
	}
}