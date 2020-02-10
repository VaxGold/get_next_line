/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:56:55 by omercade          #+#    #+#             */
/*   Updated: 2020/02/10 18:28:46 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	find_tab(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int get_next_line(int fd, char **line)
{
	int			ret;
	static char	*s;
	char		*buff;
	char		*tmp;

	if ((buff = malloc(BUFFER_SIZE + 1)) == NULL || fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		printf("El buffer es: %s y el storage: %s\n", buff, s);
		if (s == NULL)
			s = ft_strdup(buff);
		else
			s = ft_strjoin(s, buff);
		printf("El storage unido es: %s\n", s);
		if (find_tab(s) >= 0)
		{
			tmp = ft_substr(s, 0, find_tab(s));
			printf("El temporal es: %s\n", tmp);
			s = ft_substr(s, find_tab(s) + 1, ft_strlen(s) - find_tab(s));
			printf("El storage recortado es: %s\n", s);
			*line = ft_strdup(tmp);
			printf("La linea a añadir es: %s\n", *line);
			free(tmp);
			return (1);
		}
	}
	printf("El storage sobrante es: %s\n", s);
	free (buff);
	if (ret < 0)
		return (-1);
	if (s)
		*line = ft_strdup(s);
	return (0);
}
