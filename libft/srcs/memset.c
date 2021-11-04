void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned int	i;
	char	*cast_s;	
	
	i = 0;
	cast_s = (char *)s;
	while (i < n)
	{
		cast_s[i] = c;
		i++;
	}
	return (cast_s);
}