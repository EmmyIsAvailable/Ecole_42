int	ft_memcmp(void *s1, void *s2, unsigned int n)
{
	char	*cast_s1;
	char	*cast_s2;
	unsigned int	i;
	
	cast_s1 = (char *)s1;
	cast_s2 = (char *)s2;
	i = 0;
	while (cast_s1[i] && cast_s2[i] && cast_s1[i] == cast_s2[i] && i < n)
		i++;
	return (cast_s1[i] - cast_s2[i]);
}