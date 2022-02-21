
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *s);
int		search_nl(char *buffer);
void	update_buffer(char *buffer);
char	*ft_strjoin(char *s1, char *s2);



#endif
