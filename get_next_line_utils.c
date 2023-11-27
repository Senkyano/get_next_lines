/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:32:08 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/27 12:39:39 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;
	
	len = 0;
	if (!s)
		return (len);
	while (s[len] != '\0')
		len++;
	return (len);	
}

char	*ft_join(char *s1, char *s2)
{
	size_t	lentot;
	size_t	len;
	char	*new;

	if (s2 == NULL && s1 != NULL)
		return (s1);
	lentot = ft_strlen(s1) + ft_strlen(s2);
	new = malloc((lentot + 1) * sizeof(char));
	if (!new)
		return (NULL);
	len = 0;
	if (s1 != NULL)
		while (s1[len])
		{
			new[len] = s1[len];
			len++;
		}
	while (*s2 != '\0')
	{
		new[len++] = *s2;
		s2++;
	}
	new[len] = '\0';
	free(s1);
	return (new);
}
