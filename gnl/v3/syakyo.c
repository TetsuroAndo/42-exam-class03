#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*h;
	char	*d;

	h = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (h)
	{
		d = h;
		while (*s)
			*d++ = *s++;
		*d = '\0';
	}
	return (h);
}

char	*get_next_line(int fd)
{
	static char		save[BUFFER_SIZE];
	static ssize_t	pos = 0;
	static ssize_t	size = 0;
	char			line[70000];
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	while (1)
	{
		if (pos >= size)
		{
			size = read(fd, save, BUFFER_SIZE);
			pos = 0;
			if (size <= 0)
			{
				if (i == 0)
					return (NULL);
				break ;
			}
			if (i != 0 && line[i - 1] == '\n')
				break ;
			line[i++] = save[pos++];
		}
	}
	line[i] = '\0';
	return (ft_strdup(line));
}

char	*get_next_line(int fd)
{
	static char		save[BUFFER_SIZE];
	static ssize_t	pos = 0;
	static ssize_t	size = 0;
	char			line[700000];
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	while (1)
	{
		if (pos >= size)
		{
			size = read(fd, save, BUFFER_SIZE);
			pos = 0;
			if (size <= 0)
			{
				if (i == 0)
					return (NULL);
				break ;
			}
			if (i != 0 && line[i - 1] == '\n')
				break ;
			line[i++] = save[pos++];
		}
	}
	line[i] = '\0';
	return (ft_strdup(line));
}
