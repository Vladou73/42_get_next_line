/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:42:28 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/07 21:06:17 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char *res = NULL;
	int fd = open("./text.txt", O_RDONLY);

	printf("fd=%d\n", fd);
	//printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);	
	//read(fd, res, BUFFER_SIZE);
	
	res = get_next_line(fd);
	printf("res=%s\n",res);
	
	return (0);
}
