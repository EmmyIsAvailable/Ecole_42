#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*nb;
	size_t	len;
	
	nb = ft_itoa(n);
	len = ft_strlen(nb);
	write(fd, nb, len);
}