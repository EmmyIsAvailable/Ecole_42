/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:14:22 by eruellan          #+#    #+#             */
/*   Updated: 2021/12/10 15:47:14 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char *to_free)
{
	free(to_free);
	return (NULL);
}

static char	*get_line(char *to_read)
{
	int		i;
	char	*substr;

	i = 0;
	if (!to_read || !to_read[0])
		return (NULL);
	while (to_read[i] && to_read[i] != '\n')
		i++;
	i += is_new_line(&to_read[i]);
	substr = malloc(sizeof(char) * (i + 1));
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
	if (!to_read)
		return (NULL);
	while (to_read[i] && to_read[i] != '\n')
		i++;
	if (to_read[i] == '\0')
	{
		free(to_read);
		return (NULL);
	}
	i += is_new_line(&to_read[i]);
	next = malloc(sizeof(char) * (ft_strlen(to_read) - i + 1));
	if (!next)
		return (NULL);
	while (to_read[i])
		next[j++] = to_read[i++];
	next[j] = '\0';
	free(to_read);
	to_read = NULL;
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*to_read;
	char		*line;
	char		*buf;
	int			i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!prochain_n(to_read) && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (ft_free(buf));
		buf[i] = '\0';
		to_read = ft_strjoin(to_read, buf);
	}
	free(buf);
	line = get_line(to_read);
	to_read = get_next(to_read);
	return (line);
}
