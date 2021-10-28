void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;
	char	*cast_s;
	
	i = 0;
	cast_s = (char *)s;
	while (cast_s[i] && i < n)
	{
		cast_s[i] = '\0';
		i++;
	}
}