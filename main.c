/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:10:06 by omercade          #+#    #+#             */
/*   Updated: 2020/02/07 15:45:37 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int narg, char **xarg)
{
	int		fd;
	char 	*line;

	if (narg == 2)
	{
		fd = open(xarg[1], O_RDONLY);
		printf("El file descriptor es: %d\n", fd);
		while (get_next_line(fd, &line) == 1)
		{
			printf("%s\n", line);
			free(line);
		}
	}
}
