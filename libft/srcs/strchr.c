char	*ft_strchr(char *s, int c)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}