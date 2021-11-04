unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	
	i = 0;
	j = 0;
	while(src[i])
		i++;
	if(size == 0)
		return (i);
	while(src[j] && j < size - 1)
	{	
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return(i);
}