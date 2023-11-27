/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:48:44 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/27 12:45:18 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*curr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	curr = ft_read(fd, rest);
	line = ft_line(curr);
	rest = ft_rest(curr);
	return (line);
}

char	*ft_rest(char *curr)
{
	char	*rest;
	size_t	i;
	ssize_t	n;

	n = ft_pos_n(curr);
	i = 0;
	if (curr[i] == '\0' || !curr || n == -1)
		return (NULL);
	rest = malloc((ft_strlen(curr) - n + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	while (curr[++n])
		rest[i++] = curr[n];
	rest[i] = '\0';
	free(curr);
	return (rest);
}

char	*ft_line(char *curr)
{
	char	*line;
	size_t	i;

	i = 0;
	if (curr[i] == 0 || curr == NULL)
		return (NULL);
	line = malloc((ft_pos_n(curr) + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (curr[i] != '\n')
	{
		line[i] = curr[i];
		i++;
	}
	if (curr[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

ssize_t	ft_pos_n(char *curr)
{
	ssize_t	i;

	i = 0;
	while (curr[i])
	{
		if (curr[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_read(int fd, char *curr)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bitr;

	bitr = 1;
	while (bitr > 0)
	{
		bitr = read(fd, buf, BUFFER_SIZE);
		if (bitr < 0)
			return (NULL);
		buf[bitr] = '\0';
		curr = ft_join(curr, buf);
		if (ft_pos_n(buf) != -1)
			return (curr);
	}
	return (curr);
}
