#ifndef __LIBFT_H__
# define __LIBFT_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
char	**ft_split(char const *s, char c);
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