/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:48:40 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/20 18:06:50 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 10

char	*get_next_line(int fd)
{
	ssize_t	bitRead;
	ssize_t	totBitR;
	char	buffer[BUFFER_SIZE];
	char	*all;
	int		i;
	static char	*pre;

	all = NULL;
	while ((bitRead = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
			i = 0;
		all = ft_strjoin(pre, all);
		free(pre);
		while (i < bitRead)
		{
			if (buffer[i] == '\n')
			{
				all = ft_strjointo(all, buffer, totBitR + (bitRead + (i - bitRead)));
				if (i < bitRead)
					pre = ft_cpyrest(&buffer[i + 1]);
				return (all);
			}
			i++;
		}
		all = ft_strjoin(all, buffer);
		totBitR += totBitR + bitRead;
	}
	if (all != NULL && bitRead == 0)
	{
		free(pre);
		return (all);
	}
	free(all);
	return (NULL);
}
