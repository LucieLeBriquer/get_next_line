#include "get_next_line.h"

static char	*get_beg(char *s)
{
	int		i;
	int		j;
	char	*beg;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	beg = malloc((i + 1) * sizeof(char));
	if (!beg)
		return (NULL);
	j = 0;
	while (j < i)
	{
		beg[j] = s[j];
		j++;
	}
	beg[j] = '\0';
	return (beg);
}

static int	maj_buffer(char *buf, char *endl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (endl[i])
	{
		buf[i] = endl[i];
		i++;
		j++;
	}
	while (i <= BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
	return (j);
}

#include <stdio.h>

int			get_next_line(int fd, char **line)
{
	static buffer	buff;
	char			*endl;
	char			*begl;
	int				i;

	if (!line)
		return (-1);
	*line = ft_strdup("");
	if (fd < 0)
		return (-1);
	if (buff.size <= 0)
	{
		buff.size = read(fd, buff.content, BUFFER_SIZE);
		if (buff.size < 0)
		{
			*line = 0;
			return (-1);
		}
	}
	while (buff.size > 0)
	{
		if (buff.size != BUFFER_SIZE)
		{
			i = buff.size - 1;
			while (++i <= BUFFER_SIZE)
				buff.content[i] = '\0';
			i++;
		}
		endl = ft_strchr(buff.content, '\n');
		if (endl)
		{
			begl = get_beg(buff.content);
			buff.size = maj_buffer(buff.content, endl + 1);
			*line = ft_strjoin(*line, begl);
			if (!(*line))
				return (-1);
			return (1);
		}
		*line = ft_strjoin(*line, buff.content);
		buff.size = read(fd, buff.content, BUFFER_SIZE);
		if (buff.size < 0)
		{
			*line = 0;
			return (-1);
		}
	}
	return (0);
}
