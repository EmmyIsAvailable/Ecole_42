#ifndef __GET_NEXT_LINE__
# define __GET_NEXT_LINE__

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strdup(char	*str);
int		prochain_n(char *to_read);

#endif