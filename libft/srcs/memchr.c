void	*ft_memchr(void *s, int c, unsigned int n)
{
	char	*cast_s;
	unsigned int	i;
	
	cast_s = (unsigned char *)s;
	i = 0;
	while (cast_s[i] && i < n)
	{
		if (cast_s[i] == c)
			return (&cast_s[i]);
		i++;
	}
	return (0);
}