/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:29:40 by eruellan          #+#    #+#             */
/*   Updated: 2021/11/23 11:29:56 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	char	*cast_s;

	i = 0;
	cast_s = (char *)s;
	if (!s)
		return (NULL);
	if (start > ft_strlen(cast_s))
		return (NULL);
	if (start + len > ft_strlen(cast_s))
		len = ft_strlen(cast_s) - start;
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = cast_s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
