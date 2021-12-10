/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:02:05 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/10 14:49:03 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Write a function which returns a line read from a
//file descriptor
//read behaviour :
//if read fails (file not readable, invalid fd) return 0 ou -1 ?;
//if there is nothing more to read, returns 0
//return OK : read entire line from the fd
//return NULL if error occured or if there is nothing else to read	
//Important: The returned line should include the ’\n’, except if you have reached
//the end of file and there is no ’\n’.
//printf("initial st_rest=*%s*\n",st_rest);
//printf("initialize temp=*%s*\n", temp);
//printf("bytes_read=%d\n", bytes_read);
//printf("temp=*%s*\n", temp);

#include "get_next_line.h"

int	ft_read_file(int fd, int size, char **temp)
{
	int		bytes_read;
	char	*check;

	check = malloc(sizeof(char) * (size + 1));
	if (!check)
		return (0);
	bytes_read = read(fd, check, size);
	*temp = malloc(sizeof(char) * (bytes_read + 1));
	if (!*temp)
		return (0);
	ft_strlcpy(*temp, check, bytes_read + 1);
	ft_free_null_ptr(&check);
	return (bytes_read);
}

char	*ft_store_static_and_return_line(
	char **addr_res, char **addr_temp,
	char *temp2, char **addr_st_rest, int size)
{
	char	*temp3;

	temp2++;
	temp3 = malloc(sizeof(char) * (size + 1));
	if (!temp3)
		return (NULL);
	ft_strlcpy(temp3, *addr_temp, ft_strlen(*addr_temp) - ft_strlen(temp2) + 1);
	*addr_temp = *addr_res;
	*addr_res = ft_strjoin_free(addr_temp, &temp3);
	if (*temp2 != 0)
		*addr_st_rest = ft_strdup(temp2);
	ft_free_null_ptr(addr_temp);
	return (*addr_res);
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
		bytes_read = ft_read_file(fd, BUFFER_SIZE, &temp);
	if (!temp)
		return (NULL);
	temp2 = ft_strchr(temp, '\n');
	if (temp2)
		return (ft_store_static_and_return_line(
				&res, &temp, temp2, &st_rest, BUFFER_SIZE));
	res = ft_strdup(temp);
	while (bytes_read > 0)
	{
		ft_free_null_ptr(&temp);
		bytes_read = ft_read_file(fd, BUFFER_SIZE, &temp);
		temp2 = ft_strchr(temp, '\n');
		if (temp2)
			return (ft_store_static_and_return_line(
					&res, &temp, temp2, &st_rest, BUFFER_SIZE));
		temp2 = res;
		if (temp)
			res = ft_strjoin_free(&temp2, &temp);
	}
	return (res);
}
