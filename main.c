/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:33:41 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/22 17:35:29 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int fd = open("lp.txt", O_RDONLY);

	printf(" 1 %s",get_next_line(fd));
	printf(" 2 %s",get_next_line(fd));
	close(fd);
	return (0);
}