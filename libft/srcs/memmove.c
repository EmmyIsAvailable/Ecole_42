void	*ft_memmove(void *dest, void *src, unsigned int n)
{
	unsigned int	i;
	char	*cast_dest;
	char	*cast_src;
	char	*temp;
	
	i = 0;
	cast_dest = (char *)dest;
	cast_src = (char *)src;
	temp[n] = 0;
	while (i < n)
	{
		temp[i] = cast_src[i];
		cast_dest[i] = temp[i];
		i++;
	}
	return (cast_dest);
}