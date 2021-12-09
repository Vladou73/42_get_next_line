/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:37:44 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/09 12:42:33 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_null_ptr(char **ptr)
{
   
   if (*ptr)
   {
	   printf("FREEME=%p || %s\n", ptr, *ptr);
	   free(*ptr);
	   *ptr = NULL;
   }
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*ptr;
	
	if (!s)
		return (NULL);
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == '\0')
			return (NULL);
		if (*ptr == (char) c)
			return (ptr);
		ptr++;
	}
	if (c == '\0')
		return (ptr);
	return (NULL);
}


char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*dst;
	size_t	dst_size;

	dst_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(sizeof(char) * dst_size);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, dst_size);
	ft_strlcat(dst, s2, dst_size);
	ft_free_null_ptr(&s1);
	ft_free_null_ptr(&s2);
	return (dst);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dst_size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (dst_size == 0)
		return (src_size);
	i = 0;
	while (i < dst_size - 1 && i < src_size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1 < size))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != size)
		dst[i + j] = 0;
	return (ft_strlen(src) + i);
}
