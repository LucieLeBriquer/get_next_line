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

int			get_next_line(int fd, char **line)
{
	static buffer	buff;
	char			*endl;
	char			*begl;

	*line = ft_strdup("");
	if (fd < 0)
		return (-1);
	if (buff.size == 0)
		buff.size = read(fd, buff.content, BUFFER_SIZE);
	while (buff.size > 0)
	{
		endl = ft_strchr(buff.content, '\n');
		if (endl != NULL)
		{
			begl = get_beg(buff.content);
			buff.size = maj_buffer(buff.content, endl + 1);
			*line = ft_strjoin(*line, begl);
			return (1);
		}
		*line = ft_strjoin(*line, buff.content);
		buff.size = read(fd, buff.content, BUFFER_SIZE);
	}
	*line = ft_strdup("");
	buff.content[0] = '\0';
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*file;
	int		r;

	if (argc == 1)
		fd = 0;
	else
	{
		file = argv[argc - 1];
		fd = open(file, O_RDONLY);
	}
	printf("Buff_size = %d\n\n", BUFFER_SIZE);
	r = get_next_line(fd, &line);
	printf("line 1 = [%s]\tret = %d\n\n", line, r);
	r = get_next_line(fd, &line);
	printf("line 2 = [%s]\tret = %d\n\n", line, r);
	r = get_next_line(fd, &line);
	printf("line 3 = [%s]\tret = %d\n\n", line, r);
	r = get_next_line(fd, &line);
	printf("line 4 = [%s]\tret = %d\n\n", line, r);
	r = get_next_line(fd, &line);
	printf("line 5 = [%s]\tret = %d\n\n", line, r);
	r = get_next_line(fd, &line);
	printf("line 6 = [%s]\tret = %d\n\n", line, r);
	r = get_next_line(-1, &line);
	printf("line 0 = [%s]\tret = %d\n\n", line, r);
	close(fd);
	return 0;
}
