/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:02:05 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/07 19:50:38 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Write a function which returns a line read from a
//file descriptor

#include "get_next_line.h"


char *get_next_line(int fd)
{

	//1) initialize static variable and temporary pointers
	static char	*static_rest;
	char		*ptr1;
	char		*ptr2;
	char		*res;
	int			bytes_read;

	ptr1 = NULL;
	ptr2 = NULL;

	//2) open file and read file once (= not possible to close file and reopen it).

	//Read must use BUFFER_SIZE (=number of bytes read at once)
	//Read the number of chars allowed by BUFFER_SIZE and store them into temp pointer
	
	bytes_read = read(fd, ptr1, BUFFER_SIZE));
	//if bytes_read < BUFFER_SIZE : the file is finished ==> how to check this ?
	
	//need to check if there is a \n in ptr1.
	//If so, need to stop to this end of line, and store the rest in static char.
	//for the next call of function gnl, if there is sthg in static var, directly goes into static var, 
	//check for end of line. if there is one, store in res until the end of line. next call, rebelote
	


	
	//while loop : until \n is not reached, continue to append BUFFER_SIZE strings by successive readings.
	
	read(fd, ptr2, BUFFER_SIZE);
	ptr1 = ft_strjoin(ptr1, ptr2);
	//free memory : ptr2 (+ ptr1 ?)

	//once \n is reached, put the whole line in the static variable static_var, and return it

	//read behaviour :
	//if read fails (file not readable, invalid fd) return 0 ou -1 ?;
	//if there is nothing more to read, returns 0

	
	//return OK : read entire line from the fd
	//return NULL if error occured or if there is nothing else to read	
	return (st_res);
}

// call a file descriptor

//while loop : while there is sthg to read in the fd, call getnextline

//Important: The returned line should include the ’\n’, except if you have reached
//the end of file and there is no ’\n’.