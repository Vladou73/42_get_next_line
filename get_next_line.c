/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladimir <vladimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:43:31 by vladimir          #+#    #+#             */
/*   Updated: 2022/02/21 14:48:51 by vladimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

void	update_buffer(char *buffer)
{
	int i = 0;
	int j = search_nl(buffer);
	if (j == 0)
	{
		buffer[0] = '\0';
		return ;
	}
	while (buffer[j])
	{
		buffer[i] = buffer[j];
		i++;
		j++;
	}
	buffer[i] = '\0';
}

char	*get_next_line(int fd)
{
	//1) initialisation 4 variables
	static	char buffer [BUFFER_SIZE + 1];
	char	*line = NULL;
	char	*tmp = NULL;
	int		ret = 0;

	//2) check if fd is readable & init buffer
	if (read(fd, buffer, 0) == -1)
		return NULL;
	//3) initialisation line, check si il y a qqch dans buffer et 1er stockage dans line
	if (buffer[0])
		line = ft_strjoin(line, buffer);

	//4) boucle while : tant qu'il n'y a pas de newline dans buffer
	while(!search_nl(buffer))
	{
		//a) read file
		ret = read(fd, buffer, BUFFER_SIZE);
		//b) if pb, set buffer to null and return
		if (ret == 0)
		{
			update_buffer(buffer);
			return (line);
		}
		//c) terminate buffer string with null char
		buffer[ret] = '\0';
		//d) join line & buffer, free memory
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
	}
	//5) clean buffer
	update_buffer(buffer);
	//6) return line
	return (line);
}
