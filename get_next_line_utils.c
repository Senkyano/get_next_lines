/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:55:19 by marvin            #+#    #+#             */
/*   Updated: 2023/11/21 11:55:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	lentot;
	size_t	i;
	char	*new;

	lentot = (ft_strlen(str1) + ft_strlen(str2));
	new = malloc((lentot + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (str1[i])
		new[i++] = str1[i];
	while (*str2)
	{
		new[i++] = *str2;
		str2++;
	}
	new[i] = '\0';
	return (new);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_srchcara(const char *str, int c)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == c)
			return (1);
		len++;
	}
	return (0);
}

char	*ft_strjointo(char *s1, char *s2, ssize_t to)
{
	char	*new;
	ssize_t	i;

	new = malloc((to + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (*s1)
	{
		new[i++] = *s1;
		s2++;
	}
	while (*s2 && i < to)
	{
		new[i++] = *s2;
		s2++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_cpyrest(char *str)
{
	size_t	len;
	size_t	i;
	char	*pre;

	len = ft_strlen(str);
	pre = malloc((len + 1) * sizeof(char));
	if (!pre)
		return (NULL);
	i = 0;
	while (str[i])
	{
		pre[i] = str[i];
		i++;
	}
	pre[i] = '\0';
	return (pre);
}
