/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:02:05 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/10 18:53:56 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Write a function which returns a line read from a
//file descriptor

#include "get_next_line.h"

char	*ft_strjoin_free(char **s1, char **s2)
{
	char	*dst;
	size_t	dst_size;
	size_t	i;
	size_t	j;

	if (!*s1 && !*s2)
		return (NULL);
	dst_size = ft_strlen(*s1) + ft_strlen(*s2) + 1;
	dst = malloc(sizeof(char) * dst_size);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, *s1, dst_size);
	j = 0;
	i = ft_strlen(dst);
	while ((*s2)[j] && (i + j + 1 < dst_size))
	{
		dst[i + j] = (*s2)[j];
		j++;
	}
	if (i != dst_size)
		dst[i + j] = 0;
	ft_free_null_ptr(s1);
	ft_free_null_ptr(s2);
	return (dst);
}

int	ft_read_file(int fd, char **temp)
{
	int		bytes_read;
	char	*check;

	check = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!check)
		return (0);
	bytes_read = read(fd, check, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		*temp = malloc(sizeof(char) * (bytes_read + 1));
		if (!*temp)
			return (0);
		ft_strlcpy(*temp, check, bytes_read + 1);
	}
	ft_free_null_ptr(&check);
	return (bytes_read);
}

char	*ft_store_static_and_return_line(
	char **addr_res, char **addr_temp,
	char *temp2, char **addr_st_rest)
{
	char	*temp3;

	temp2++;
	temp3 = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp3)
		return (NULL);
	ft_strlcpy(temp3, *addr_temp, ft_strlen(*addr_temp) - ft_strlen(temp2) + 1);
	*addr_res = ft_strjoin_free(addr_res, &temp3);
	if (*temp2 != 0)
		*addr_st_rest = ft_strdup(temp2);
	ft_free_null_ptr(addr_temp);
	ft_free_null_ptr(&temp3);
	return (*addr_res);
}

char	*ft_test(char **temp, char **res, char **st_rest, int fd)
{
	char	*temp2;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		ft_free_null_ptr(temp);
		bytes_read = ft_read_file(fd, temp);
		if (bytes_read <= 0)
			break ;
		temp2 = ft_strchr(*temp, '\n');
		if (temp2)
			return (ft_store_static_and_return_line(res, temp,
					temp2, st_rest));
		*res = ft_strjoin_free(res, temp);
	}
	return (*res);
}

char	*get_next_line(int fd)
{
	static char	*st_rest;
	char		*res;
	char		*temp;
	char		*temp2;
	int			bytes_read;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	res = NULL;
	if (st_rest)
	{
		temp = ft_strdup(st_rest);
		ft_free_null_ptr(&st_rest);
	}
	else
	{
		bytes_read = ft_read_file(fd, &temp);
		if (bytes_read <= 0)
			return (NULL);
	}
	temp2 = ft_strchr(temp, '\n');
	if (temp2)
		return (ft_store_static_and_return_line(&res, &temp, temp2, &st_rest));
	res = ft_strdup(temp);
	return (ft_test(&temp, &res, &st_rest, fd));
}
