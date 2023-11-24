/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:33:41 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/24 15:18:45 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int fd = open("lp.txt", O_RDONLY);
	char	*po;
	
	po = get_next_line(fd);
	printf("%s",po);
	if (po != NULL)
		free(po);
	close(fd);
	return (0);
}