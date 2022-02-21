/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladimir <vladimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:04:09 by vladimir          #+#    #+#             */
/*   Updated: 2022/02/21 14:40:19 by vladimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	search_nl(char *buffer)
{
	int i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	char *new_s = NULL;

	if (!s2)
		return (s1);
	if (search_nl(s2))
		new_s = malloc(sizeof(char) * (ft_strlen(s1) + search_nl(s2) + 1));
	else
		new_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
		return (NULL);
	//printf("s1=%s, s2=%s\n", s1, s2);
	while (s1 && s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		new_s[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
	{
		new_s[i + j] = '\n';
		j++;
	}
	new_s[i + j] = '\0';
	return (new_s);
}
