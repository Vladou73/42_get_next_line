/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:37:44 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/07 18:38:19 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	dst_size;

	dst_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(sizeof(char) * dst_size);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, dst_size);
	ft_strlcat(dst, s2, dst_size);
	return (dst);
}


