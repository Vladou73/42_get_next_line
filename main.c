/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:42:28 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/10 14:12:54 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char *res = NULL;
	int fd = open("./text.txt", O_RDONLY);

	printf("fd=%d\n", fd);
	printf("BUFFER_SIZE=%d\n\n\n", BUFFER_SIZE);
	//read(fd, res, BUFFER_SIZE);
	
	int i = 1;
	while (i < 100)
	{
		res = get_next_line(fd);
		printf("line%d=***%s***\n\n",i,res);
		if (*res == 0)
			break;
		i++;
	}
	close(fd);
	return (0);
}
