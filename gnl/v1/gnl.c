/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:25:57 by teando            #+#    #+#             */
/*   Updated: 2024/12/14 09:12:03 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

size_t	ft_strlen(char *s)
{
	const char	h = s;

	while (*s)
		s++;
	return (s - h);
}

char	*ft_strdup(char *s)
{
	char	*dst;
	char	*head;

	if (!dst)
		return (NULL);
	head = dst;
	while (*s)
		*dst++ = *s++;
	*dst = '\0';
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	size;
	static ssize_t	pos;
	char			line[70000];
	size_t			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	while (1)
	{
		if (pos >= size)
		{
			size = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
			if (size <= 0)
				break ;
		}
		if (buffer[pos] == '\n')
			break ;
		line[i++] = buffer[pos++];
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt    dst = malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!dst)
        return (NULL);
    head = dst;
    while (*s)
        *dst++ = *s++;
    *dst = '\0';
    return (head); ", O_RDONLY);
	get_next_line(fd);
	printf("%s\n", s);
	free(s);
	return (0);
}
