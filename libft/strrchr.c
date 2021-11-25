/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:19:31 by eruellan          #+#    #+#             */
/*   Updated: 2021/11/23 11:19:46 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*cast_s;

	i = ft_strlen(s);
	cast_s = (char *)s;
	if (c == '\0')
		return ("\0");
	while (cast_s[--i])
	{
		if (cast_s[i] == c)
			return (&cast_s[i]);
	}
	return (NULL);
}
