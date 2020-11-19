#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct
{
	int		size;
	char	content[BUFFER_SIZE + 1];
}			buffer;

char    *join_and_realloc(char *s, char *buf, int size);
int		find_char_index(char *str, char c);
int		get_next_line(int fd, char **line);
char    *ft_strndup(char *str, int n);

#endif
