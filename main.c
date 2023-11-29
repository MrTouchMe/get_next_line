/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:06:57 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/11/29 20:51:54 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	fd = open("test.txt", O_RDONLY);
	char	*line;
	line = get_next_line(fd);
	while(line && line[0] != '\0')
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	return (0);
}
