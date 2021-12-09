/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:01:08 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/09 14:01:59 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/types.h>
#include <unistd.h>
#include <libc.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE
#endif


char	*get_next_line(int fd);
int		ft_read_file(int fd, int size, char **temp);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_free(char **s1, char **s2);
size_t	ft_strlcpy(char *dst, char *src, size_t dst_size);
char	*ft_strdup(char *s);
size_t	ft_strlcat(char *dst, char *src, size_t size);
void	ft_free_null_ptr(char **ptr);

#endif