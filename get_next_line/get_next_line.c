/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:48:44 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/24 16:58:09 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*pre;
	char		*test;
	t_recup		stock;

	pre = ft_read(fd);
	test = ft_separateur(pre);
	return (test);
}

char	*ft_separateur(char *pre)
{
	size_t	lenton;
	char	*curr;

	lenton = ft_position_n(pre);
	curr = malloc((lenton + 1) * sizeof(char));
	curr[lenton] = '\0';
	while (lenton > 0)
	{
		lenton--;
		curr[lenton] = pre[lenton];
	}
	
	return (curr);
}

size_t	ft_position_n(char *pre)
{
	size_t	i;

	i = 0;
	while (pre[i] != '\0')
	{
		if (pre[i++] == '\n')
			return (i);
	}
	return (-1);
}

char	*ft_read(int fd)
{
	char	*cur;
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bitr;
	ssize_t	i;

	cur = NULL;
	bitr = 1;
	while (bitr > 0)
	{
		bitr = read(fd, buf, BUFFER_SIZE);
		buf[bitr] = '\0';
		cur = ft_join(cur, buf);
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
				return (cur);
			i++;
		}
	}
	return (cur);
}
