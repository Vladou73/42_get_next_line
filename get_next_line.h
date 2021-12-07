/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:01:08 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/07 19:11:24 by vnafissi         ###   ########.fr       */
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

#endif