/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:48:44 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/23 16:00:59 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*current;
	char		buff[BUFFER_SIZE + 1];
	ssize_t		bitR;

	if (rest != NULL)
	{
		if (check_n(rest) >= 0)
		{
			current = ft_to_n(rest, check_n(rest));
			rest = ft_rest(rest, check_n(rest));
			return (current);
		}
		current = rest;
	}
	while ((bitR = read(fd, buff, BUFFER_SIZE)) > 0 && check_n(buff) == -1)
	{
		
	}
	return (current);
}

char	*read

int	check_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_rest(char *rest, int i)
{
	char	*tmp;
	int		j;

	tmp = malloc(((BUFFER_SIZE - i) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	j = 0;
	while (rest[++i])
	{
		tmp[j] = rest[i];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_to_n(char *rest, int i)
{
	char	*tmp;

	tmp = malloc((i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[i] = '\0'
	while (--i >= 0)
	{
		tmp[i] = rest[i];
	}
	return (tmp);
}
