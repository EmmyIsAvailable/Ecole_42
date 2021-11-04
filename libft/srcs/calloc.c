#include <libft.h>

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void	*ptr;
	unsigned int	i;
	int	*cast_ptr;
	
	i = 0;
	if (size == 0 || nmemb == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!(ptr))
		return (NULL);
	cast_ptr = (int *)ptr;
	while (i++ < nmemb)
		cast_ptr[i] = 0;
	return (cast_ptr);
}