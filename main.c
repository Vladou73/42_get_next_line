/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:42:28 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/09 11:07:42 by vnafissi         ###   ########.fr       */
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
	
	int i = 0;
	while (i < 5)
	{
		res = get_next_line(fd);
		printf("res=***%s***\n\n\n\n",res);
		i++;
	}
	close(fd);
	return (0);
}
