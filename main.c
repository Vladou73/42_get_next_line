/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:42:28 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/07 19:34:12 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char c[1000];
	int fd = open("./text.txt", O_RDONLY);

	printf("fd=%d\n", fd);
	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	read(fd, c, BUFFER_SIZE);
	printf("c=%s\n",c);
	
	return (0);
}
