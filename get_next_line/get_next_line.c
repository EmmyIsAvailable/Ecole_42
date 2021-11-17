#include "get_next_line.h"
#include <stdio.h>
static char	*free_ligne(char *to_free, char *retour)
{
	to_free = NULL;
	free(to_free);
	return (retour);
}

static char	*get_line(char *to_read)
{
	int		i;
	char	*substr;
	
	i = 0;
	
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			i;
	static char	*to_read;
	char		*line;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!prochain_n(to_read) && (i  > 0))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)	
			return (free_ligne(to_read, NULL));
		buf[i] = '\0';
		to_read = "";
		to_read = ft_strjoin(to_read, buf);
		if (!to_read)
			return (free_ligne(to_read, NULL));
	}
	if (i == 0 && (to_read == NULL || buf[0] == '\0'))
		return ("");
	return (to_read);
}