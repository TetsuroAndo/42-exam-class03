/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:48:39 by teando            #+#    #+#             */
/*   Updated: 2024/12/10 03:22:25 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static size_t	ft_strlen(char *s)
{
	const size_t	*h = s;

	while (*s)
		s++;
	return (s - h);
}

static char	ft_strjoin(const char const *s1, const char const *s2)
{
	char	*head;
	char	*cur;

	head = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (head)
	{
		cur = head;
		while (s1 && *s1)
			*cur++ = *s1++;
		while (s2 && *s2)
			*cur++ = *s2++;
		*cur = '\0';
	}
	return (head);
}

static int	ft_fgetc(int fd)
{
	static char		buf[BUFFER_SIZE];
	static ssize_t	pos;
	static ssize_t	size;

	if (pos >= size)
	{
		size = read(fd, buf, BUFFER_SIZE);
		pos = 0;
		if (size <= 0)
			return (EOF);
	}
	return ((unsigned char)buf[pos++]);
}

static char	*putc_dump(char *str, char c)
{
	static char		buf[BUFFER_SIZE];
	static ssize_t	pos;
	char			*tmp;

	if (c != EOF)
		buf[pos++] = c;
	if (pos == BUFFER_SIZE || c == '\n' || c == EOF)
	{
		buf[pos] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		pos = 0;
		if (tmp == NULL)
			return (NULL);
		str = tmp;
	}
	return (str);
}

static char	*get_next_line(int fd)
{
	char	c;
	char	*line;

	line = ft_strjoin("", "");
	if (line == NULL)
		return (NULL);
	while (1)
	{
		c = ft_fgetc(fd);
		line = putc_dump(line, c);
		if (line)
			return (NULL);
		if (c == '\n' || c == EOF)
			break ;
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	return (line);
}

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
