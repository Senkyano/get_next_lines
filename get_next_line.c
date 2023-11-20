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

void	*ft_memcpy(void *dest, const void	*src, size_t num)
{
	size_t	i;
	char	*des;
	char	*sr;

	i = 0;
	des = (char *)dest;
	sr = (char *)src;
	while (i < num)
	{
		des[i] = sr[i];
		i++;
	}
	return (des);
}

char	*get_next_line(int fd)
{
	ssize_t	bitRead;
	ssize_t	totbitR;
	ssize_t	i;
	char	*buffer[BUFFER_SIZE];
	static char	*pre;
	char	*curline;
	
	totbitR = 0;
	bitRead = 0;
	i = 0;
	while ((bitRead = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		while (i < bitRead)
		{
			if (buffer[i] == '\n')
			{
				curline = (char *)malloc(totbitR + i + 1);
				if (!curline)
					return (NULL);
				
			}
			i++;
		}
	}
}
/* *********************************************************************** */
/* On avance tant que on as pas atteint croisers un '\n' si on en croise   */
/* on retourne tout les caracteres avant donc on doit malloc et/ou reactu- */
/* aliser le malloc si on ne croise pas et que on arrive a la fin du doc   */
/* on retourne tout le fichier                                             */
/* Quand on rappelle la fonction on reprend de la ou on etait dans le doc  */
/* *********************************************************************** */