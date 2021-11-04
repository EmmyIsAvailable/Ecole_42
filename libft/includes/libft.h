#ifndef __LIBFT_H__
# define __LIBFT_H__

#include <stdlib.h>
#include <string.h>

void	*ft_memset(void *s, int c, unsigned int n);
void	*ft_memmove(void *dest, void *src, unsigned int n);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
int		ft_memcmp(void *s1, void *s2, unsigned int n);
void	*ft_memchr(void *s, int c, unsigned int n);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	*ft_calloc(unsigned int nmemb, unsigned int size);
void	ft_bzero(void *s, unsigned int n);
int		ft_atoi(const char *str);
int		ft_isprint(int c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif