#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)src;
	if (!dst)
		return (0);
	while (str[i] && i + 1 < size)
	{
		dst[i] = str[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	join = malloc((l1 + l2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	(void)ft_strlcpy(join, s1, l1 + 1);
	(void)ft_strlcpy(join + l1, s2, l2 + 1);
	/*free(s1);
	free(s2);*/
	return (join);
}

char	*ft_strchr(char *s, int c)
{
	size_t	n;
	size_t	i;
	char	*str;

	n = ft_strlen(s);
	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	if (c == 0)
		return (str + n);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	l;
	size_t	i;
	char	*dup;

	l = ft_strlen(s);
	dup = malloc((l + 1) * sizeof(char));
	i = -1;
	if (!dup)
		return (NULL);
	while (++i < l)
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
