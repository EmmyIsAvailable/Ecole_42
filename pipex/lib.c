#include "pipex.h"

size_t  ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

void    ft_putstr_fd(char *s, int fd)
{
        size_t  len;

        if (!s || !fd)
                return ;
        len = ft_strlen(s);
        write(fd, s, len);
}
