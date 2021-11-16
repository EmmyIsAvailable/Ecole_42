#include "get_next_line.h"

static char	*free_ligne(char *to_free, char *retour)
{
	to_free = NULL;
	free(to_free);
	return (retour);
}

char	*get_next_line(int fd)
{
	static char	*deja_lu;
	char		*buf;
	int			i;
	char		*a_lire;

	a_lire = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, BUFFER_SIZE) = -1)
		return (NULL);
	if(deja_lu)
	{
		a_lire = ft_strdup(deja_lu);
		if (!a_lire)
			return (free_ligne(a_lire, NULL);
	}
	while (prochain_n(a_lire) && (i = read(fd, buf, BUFFER_SIZE)) > 0)
	{	
		buf[i] = '\0';
		a_lire = '\0';
		a_lire = ft_strjoin(a_lire, buf);
		if (!a_lire)
			return (free_ligne(a_lire, NULL);
	}
}