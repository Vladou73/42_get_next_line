/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:02:05 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/07 21:52:32 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Write a function which returns a line read from a
//file descriptor

#include "get_next_line.h"


char *get_next_line(int fd)
{

	//1) initialize static variable and temporary pointers
	static char	*st_rest;
	char		*res;
	char		*temp;
	int			bytes_read;

	//res = NULL;
	temp = NULL;

	printf("BUFFER_SIZE=%d\n",BUFFER_SIZE);

	//2) open file and read file once (= not possible to close file and reopen it).

	//Read must use BUFFER_SIZE (=number of bytes read at once)

	//a)allocate memory to a ptr (size of BUFFER_SIZE). if fail, protect
	//b)Read the number of chars allowed by BUFFER_SIZE and store them into the pointer
	res = malloc(sizeof(char) * (sizeof(BUFFER_SIZE) + 1));
	if (!res)
		return NULL; //+ FREE ?
	
	bytes_read = read(fd, res, BUFFER_SIZE);
	printf("bytes_read=%d\n",bytes_read);
	//if bytes_read < BUFFER_SIZE : the file is finished ==> how to check this ?
	
	//need to check if there is a \n in res.
	//If so, need to stop to this end of line, and store the rest in static char.
	//for the next call of function gnl, if there is sthg in static var, directly goes into static var, 
	//check for end of line. if there is one, store in res until the end of line. next call, rebelote
	printf("res=%s\n",res);
	temp = ft_strchr(res, (int)('\n'));
	
	//while (*res)
	//{
	//	printf("%c\n",*res);
	//	//if (*ptr == (char) c)
	//	//	return (ptr);
	//	res++;
	//}
	
	printf("temp=%s\n",temp);
	if (temp)
	{
		printf("il y a un retour a la ligne dans notre buffer\n");
		res = malloc(sizeof(char) * (ft_strlen(res) - ft_strlen(temp) + 1)); //FREE ?
		ft_strlcpy(res, res, ft_strlen(res) - ft_strlen(temp) + 1); 
		
		st_rest = ft_strdup(temp); //FREE ?
	}
	
	
	printf("st_rest=%s\n",st_rest);
	
	//while loop : until \n is not reached, continue to append BUFFER_SIZE strings by successive readings.
	
	//read(fd, temp, BUFFER_SIZE);
	//res = ft_strjoin(res, temp);
	//free memory : temp (+ res ?)

	//once \n is reached, put the whole line in the static variable static_var, and return it

	//read behaviour :
	//if read fails (file not readable, invalid fd) return 0 ou -1 ?;
	//if there is nothing more to read, returns 0

	
	//return OK : read entire line from the fd
	//return NULL if error occured or if there is nothing else to read	
	return (res);
}

// call a file descriptor

//while loop : while there is sthg to read in the fd, call getnextline

//Important: The returned line should include the ’\n’, except if you have reached
//the end of file and there is no ’\n’.