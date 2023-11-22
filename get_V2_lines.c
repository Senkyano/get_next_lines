/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:48:40 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/22 17:39:37 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 12

char	*get_next_line(int fd)
{
	ssize_t		bitR;
	ssize_t		totR;
	char		buf[BUFFER_SIZE + 1];
	static char	*pre;
	char		*all;
	char		*tmp;
	int			i;
	
	totR = 0;
	all = "\0";
	while ((bitR = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		i = 0;
		while (i < bitR)
		{
			if (buf[i] == '\n')
			{
				all = ft_to_n(all , buf, (totR + i));
// Malloc tout ceux qui l'a pu lire avant de trouve le retour a la ligne
				/*if ((bitR - (i + 1)) > 0)
					pre = ft_after_n(&buf[i + 1], bitR - i);*/
// Malloc le reste du buf si il reste des choses a copier pour la prohaine utilisation
				return (all);
			}
			i++;
		}
		totR += bitR;
		all = ft_to_n(all, buf, totR);
// Malloc tous pour forme une ligne si on as pas encore rencontrer un retour a la line
	}
	return (all);
}

char	*ft_to_n(char *all, char *buf, ssize_t totR)
{
	char	*newAll;
	ssize_t	i;

	newAll = malloc((totR + 1) * sizeof(char));
	if (!newAll)
		return (NULL);
	i = 0;
	while (*all != '\0')
	{
		newAll[i++] = *all;
		all++;
	}
	while (*buf != '\n' && *buf)
	{
		newAll[i++] = *buf;
		buf++;
	}
	newAll[i + 1] = '\0';
	return (newAll);
}





char	*ft_malloc(char *cpy, ssize_t len)
{
	char	*tmp;
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[len] = '\0';
	while (len)
	{
		len--;
		tmp[len] = cpy[len];
	}
	return (tmp);
}
/* *********************************************************************** */
/* On avance tant que on as pas atteint croisers un '\n' si on en croise   */
/* on retourne tout les caracteres avant donc on doit malloc et/ou reactu- */
/* aliser le malloc si on ne croise pas et que on arrive a la fin du doc   */
/* on retourne tout le fichier                                             */
/* Quand on rappelle la fonction on reprend de la ou on etait dans le doc  */
/* *********************************************************************** */