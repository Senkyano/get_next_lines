/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:48:44 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/23 13:52:25 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*pre; // ceux qu'il y avant
	char		buf[BUFFER_SIZE + 1]; //  en cours de lecture
	char		*tmp; // temporaire pour stocker / deplacer
	ssize_t		bitR;
	ssize_t		totR;
	ssize_t		i;

	i = 0;
	tmp = "\0";
	totR = 0;
	if (pre != NULL)
	{
		while (pre[i])
		{
			if (pre[i] == '\n')
			{
				tmp = ft_div_rest(pre, i);
				pre = ft_rest(pre, i);
				return (tmp);
			}
			i++;
		}
		tmp = pre;
	}
	while ((bitR = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		i = 0;
		buf[BUFFER_SIZE] = '\0';
		while (i < BUFFER_SIZE)
		{
			if (buf[i] == '\n')
			{
				tmp = ft_to_n(tmp, buf, i);
				pre = ft_rest(buf, i);
				return (tmp);
			}
			i++;
		}
		totR += bitR;
		tmp = ft_global(tmp, buf, totR);
	}
	return (tmp);
}

//si dans pre il y a un retour a la ligne on print jusqu'au retour
//la ligne mais si il n'y a pas il faut rajoute a tmp;
char	*ft_div_rest(char *pre, ssize_t i)
{
	char	*tmp;
	ssize_t	j;

	tmp = malloc((i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		tmp[j] = pre[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_rest(char *buf, ssize_t i)
{
	char	*tmp;
	ssize_t 	j;
	
	tmp = malloc((BUFFER_SIZE - i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	j = 0;
	if (buf[i] == '\n')
		i++;
	while (i < BUFFER_SIZE && buf[i] != '\0')
	{
		tmp[j] = buf[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_to_n(char *all, char *buf, ssize_t len_to_n)
{
	char	*tmp;
	ssize_t	i;

	tmp = malloc((ft_strlen(all) + len_to_n  + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (all[i] != '\0')
	{
		tmp[i]= all[i];
		i++;
	}
	while (*buf != '\0' && i <= len_to_n + ft_strlen(all))
	{
		tmp[i] = *buf;
		i++;
		buf++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_global(char *current, char *buf, ssize_t lenAll)
{
	char	*tmp;
	ssize_t	i;

	tmp = malloc((lenAll + 1) * sizeof(char));
	if 	(!tmp)
		return (NULL);
	i = 0;
	while (current[i] != '\0')
	{
		tmp[i] = current[i];
		i++;
	}
	while (*buf)
	{
		tmp[i] = *buf;
		buf++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
