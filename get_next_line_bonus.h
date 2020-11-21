/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:54:58 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/21 14:14:22 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# ifndef FD_MAX
#  define FD_MAX 256
# endif

typedef struct
{
	int		size;
	char	content[BUFFER_SIZE + 1];
}			t_buffer;

char		*join_and_realloc(char *s, char *buf, int size);
char		*ft_strndup(char *str, int n);
int			find_char_index(char *str, char c);
int			get_next_line(int fd, char **line);

#endif