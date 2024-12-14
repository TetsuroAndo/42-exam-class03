/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:37:05 by teando            #+#    #+#             */
/*   Updated: 2024/12/14 10:04:58 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

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
	char	*dst;
	char	*head;

	dst = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	head = dst;
	while (*s)
		*dst++ = *s++;
	*dst = '\0';
	return (head);
}

char	*get_next_line(int fd)
{
	static char		saved[BUFFER_SIZE];
	static ssize_t	size = 0;
	static ssize_t	pos = 0;
	char			line[70000] = {0};
	size_t			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (pos >= size)
		{
			size = read(fd, saved, BUFFER_SIZE);
			pos = 0;
			if (size <= 0)
			{
				if (i == 0)
					return (NULL);
				break ;
			}
		}
		if (i != 0 && line[i - 1] == '\n')
			break ;
		line[i++] = saved[pos++];
	}
	line[i] = '\0';
	return (ft_strdup(line));
}

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	close(fd);
	return (0);
}
