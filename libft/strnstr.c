char	*ft_strnstr(char *s1, char *s2, unsigned int n)
{
	int	i;
	unsigned int	j;
	
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