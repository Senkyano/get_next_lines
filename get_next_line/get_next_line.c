/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:48:44 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/25 18:24:57 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*pre;
	t_recup		stock;

	if (pre != NULL)
	{
		if (ft_position_n(pre) != -1)
			stock.curr = pre;
		if (ft_position_n(pre) == -1)
			stock.curr = ft_join(pre, ft_read(fd));
	}
	if (pre == NULL)
		stock.curr = ft_read(fd);
	stock = ft_separateur(stock.curr);
	pre = stock.rest;
	return (stock.curr);
}

t_recup	ft_separateur(char *pre)
{
	size_t	lenton;
	size_t	lenr;
	t_recup	stock;

	lenton = ft_position_n(pre);
	stock.curr = malloc((lenton + 1) * sizeof(char));
	stock.curr[lenton] = '\0';
	while (lenton > 0)
	{
		lenton--;
		stock.curr[lenton] = pre[lenton];
	}
	lenton = ft_position_n(pre);
	lenr = ft_strlen(pre) - lenton;
	stock.rest = malloc((lenr + 1) * sizeof(char));
	stock.rest[lenr] = '\0';
	while (lenr > 0)
	{
		lenr--;
		stock.rest[lenr] = pre[lenton++];
	}
	free(pre);
	return (stock);
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
