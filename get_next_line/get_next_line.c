/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:14:22 by eruellan          #+#    #+#             */
/*   Updated: 2021/11/26 15:57:44 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_ligne(char *to_free, char *retour)
{
	free(to_free);
	to_free = NULL;
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
	if (to_read[i] == '\n')
		i++;
	substr = (char *)malloc(sizeof(char) * (i + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (to_read[++i] && to_read[i] != '\n')
		substr[i] = to_read[i];
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
		return (free_ligne(to_read, NULL));
	next = (char *)malloc(sizeof(char) * (ft_strlen(to_read) - i + 1));
	if (!next)
		return (free_ligne(to_read, NULL));
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

static char	*get_to_read(int fd, char *buf, char *to_read, int i)
{
	while (!prochain_n(to_read) && (i > 0))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (free_ligne(buf, NULL));
		buf[i] = '\0';
		to_read = ft_strjoin(to_read, buf);
		if (!to_read)
			return (free_ligne(buf, NULL));
	}
	free(buf);
	return (to_read);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*to_read;
	char		*line;
	char		*buf;

	i = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1
		|| (!prochain_n(to_read) && to_read))
	{
		free (buf);
		return (free_ligne(to_read, NULL));
	}
	to_read = get_to_read(fd, buf, to_read, i);
	line = get_line(to_read);
	if (!prochain_n(line))
	{
		free(to_read);
		return (free_ligne(line, NULL));
	}
	to_read = get_next(to_read);
	if (i == 0)
	{
		free(line);
		return (free_ligne(to_read, ""));
	}
	return (line);
}
