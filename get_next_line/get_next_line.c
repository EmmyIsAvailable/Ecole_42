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
	if (!to_read)
		return (NULL);
	while (to_read[i] && to_read[i] != '\n')
		i++;
	substr = (char *)malloc(sizeof(char) * (i + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (to_read[i] && to_read[i] != '\n')
	{
		substr[i] = to_read[i];
		i++;
	}
	if (to_read[i] == '\n')
	{
		substr[i] = '\n';
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static char	*get_next(char *to_read)
{
	int		i;
	int		j;
	char	*next;
	
	i = 0;
	j = 0;
	while (to_read[i] && to_read[i] != '\n')
		i++;
	if (to_read[i] == '\0')
	{
		free (to_read);
		return (NULL);
	}
	next = (char *)malloc(sizeof(char) * (ft_strlen(to_read) - i + 1));
	if (!next)
		return (NULL);
	i++;
	while (to_read[i + j])
	{
		next[j] = to_read[i + j];
		j++;
	}
	next[j] = '\0';
	free(to_read);
	return (next);
}
// à vérifier : que l'on lise bien la ligne jusqu'au dernier \n possible dans la limite du BUFFER_SIZE
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
	if (!prochain_n(to_read) && to_read)
		return (NULL);
	while (!prochain_n(to_read) && (i > 0))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)	
			return (free_ligne(buf, NULL));
		buf[i] = '\0';
		to_read = ft_strjoin(to_read, buf);
		if (!to_read)
			return (free_ligne(to_read, NULL));
	}
	free(buf);
	line = get_line(to_read);
	if (!prochain_n(line))
		return (NULL);
	to_read = get_next(to_read);
	if (i == 0)
		return ("");
	return (line);
}