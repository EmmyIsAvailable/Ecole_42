unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	len_dst;
	unsigned int	len_src;
	unsigned int	i;
	
	len_dst = 0;
	len_src = 0;
	i = 0;
	while(dst[len_dst])
		len_dst++;
	while (src[len_src])
		len_src++;
	if(size - len_dst - 1 < 0)
		return(size + len_src);
	while(src[i] && len_dst + i < size - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return(len_dst + len_src);
}