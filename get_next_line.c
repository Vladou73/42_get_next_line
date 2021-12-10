/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:02:05 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/10 12:18:29 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Write a function which returns a line read from a
//file descriptor

#include "get_next_line.h"

int	ft_read_file(int fd, int size, char **temp)
{
	int		bytes_read;
	char	*check;

	check = malloc(sizeof(char) * (size + 1)); //check is used in case bytes_read < size
	if (!check)
		return (0);
	bytes_read = read(fd, check, size);
	*temp = malloc(sizeof(char) * (bytes_read + 1));
	if (!*temp)
		return (0);
	ft_strlcpy(*temp, check, bytes_read + 1);
	return (bytes_read);
}

char *get_next_line(int fd)
{

	//1) initialize static variable and temporary pointers
	static char	*st_rest;
	char		*res;
	char		*temp;
	char		*temp2;
	char		*temp3;
	int			i;
	int			bytes_read;
	
	res = NULL;
	temp = NULL;
	temp2 = NULL;
	temp3 = NULL;
	
	//printf("initial st_rest=*%s*\n",st_rest);
	
	//******************* INITIALIZE ***********************

	//initialization first read
	if (st_rest) // if there is already data in st_rest, don't read file. initialize temp with data stored in static (ie data stored from last read)
		{
			temp = ft_strdup(st_rest);
			ft_free_null_ptr(&st_rest);
		}
	else
		bytes_read = ft_read_file(fd, BUFFER_SIZE, &temp);
	if (!temp)
		return (NULL);
	//printf("initialize temp=*%s*\n", temp);

	//search for \n or \0 (end of file) in temp
	temp2 = ft_strchr(temp, '\n');
	if (temp2) // si on a trouve un \n on passe au caractere suivant le retour a la ligne. \\\\\ATTENTION///// si on est en fin de document est ce que ca fonctionne ?
		temp2++;
	//printf("initialize temp2=*%s*\n", temp2);

	//if there is a \n, store 1st line in res and return it. Store the rest in st_rest
	if (temp2)
	{
		res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!res) //si l'allocation echoue il faut free tous les autres pointeurs ?
			return (NULL);
		ft_strlcpy(res, temp, ft_strlen(temp) - ft_strlen(temp2) + 1);
		if (*temp2 != 0) //if there is something more in temp2, store it in st_rest.
			st_rest = ft_strdup(temp2);
		ft_free_null_ptr(&temp);
		return (res);
	}
	
	//store in res what was retrieved from initialization
	res = ft_strdup(temp); //temp is freed in while loop
	//printf("initialize res=*%s*\n\n", res);

	//******************* ENTER WHILE LOOP ***********************
	i = 0;
	while (bytes_read > 0)
	{
		//printf("loop %d\n", i);
		//free if needed ptr temp, then read file and store in it
		ft_free_null_ptr(&temp);
		bytes_read = ft_read_file(fd, BUFFER_SIZE, &temp);
		//printf("bytes_read=%d\n", bytes_read);
		//printf("temp=*%s*\n", temp);

		//search for linebreak in temp
		temp2 = ft_strchr(temp, '\n');
		if (temp2) // si on a trouve un \n on passe juste au caractere suivant
			temp2++;
		//printf("temp2=*%s*\n", temp2); //dans temp2 il y a le reste du texte a stocker dans la variable static
		
		//if there is a \n, store the totality of the 1st line in res and return it. Store the rest (after line break) in st_rest
		if (temp2)
		{
			//we need to concatenate content already stored in res (beginning of line) + the content coming from last read untli end of line
			temp3 = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			ft_strlcpy(temp3, temp, ft_strlen(temp) - ft_strlen(temp2) + 1);
			temp = res; // store begining of line in temp
			res = ft_strjoin_free(&temp, &temp3);
			if (*temp2 != 0)
				st_rest = ft_strdup(temp2);
			//printf("st_rest=*%s*\n", st_rest);
			ft_free_null_ptr(&temp); //reinitialize temp at the end
			return (res);
		}
		
		//on join le contenu deja present dans res avec le nouveau contenu lu present dans temp. pour cela on alloue
		temp2 = res;
		if (temp)
			res = ft_strjoin_free(&temp2, &temp);
		//printf("res=*%s*\n\n", res);
		i++;
	}

	//read behaviour :
	//if read fails (file not readable, invalid fd) return 0 ou -1 ?;
	//if there is nothing more to read, returns 0
	
	//return OK : read entire line from the fd
	//return NULL if error occured or if there is nothing else to read	
	return (res);
}

//Important: The returned line should include the ’\n’, except if you have reached
//the end of file and there is no ’\n’.