/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:46:34 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/25 18:45:50 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <bsd/string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3

#endif

typedef struct	s_recup
{
	char	*rest;
	char	*curr;
}	t_recup;

char	*get_next_line(int fd);
char	*ft_read(int fd);
size_t	ft_strlen(const char *s);
char	*ft_join(char *s1, char *s2);
ssize_t	ft_position_n(char *pre);
t_recup	ft_separateur(char *pre);

#endif