/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:19:58 by eruellan          #+#    #+#             */
/*   Updated: 2021/11/23 11:29:31 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_charset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	nb_total(char *s1, char *set)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	while (s1[len] && is_in_charset(s1[len], set))
		len--;
	while (s1[i++] && is_in_charset(s1[i], set))
		len--;
	return (len);
}

static char	*fill_str(char *str, char *s1, char *set)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = nb_total(s1, set);
	while (s1[i] && is_in_charset(s1[i], set))
		i++;
	while (s1[i] && !is_in_charset(s1[i], set))
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*str_trimmed;
	char	*cast_s1;
	char	*cast_set;

	cast_s1 = (char *)s1;
	cast_set = (char *)set;
	len = nb_total(cast_s1, cast_set);
	if (!s1 || !set)
		return (NULL);
	str_trimmed = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_trimmed)
		return (NULL);
	fill_str(str_trimmed, cast_s1, cast_set);
	return (str_trimmed);
}
