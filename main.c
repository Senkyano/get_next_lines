/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:33:41 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/27 12:41:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int fd = open("lp.txt", O_RDONLY);
	char	*po;
	int		i;

	i = 0;
	while (i < 3)
	{
		po = get_next_line(fd);
		printf("%s",po);
		i++;
		free(po);
	}
	close(fd);
	return (0);
}