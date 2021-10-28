void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;
	char	*cast_dest;
	char	*cast_src;
	
	i = 0;
	cast_dest = (char *)dest;
	cast_src = (char *)src;
	while (i < n)
	{
		cast_dest[i] = cast_src[i];
		i++;
	}
	return (cast_dest);
}