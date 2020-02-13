/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:56:55 by omercade          #+#    #+#             */
/*   Updated: 2020/02/13 12:30:01 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		find_tab(const char *s)
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

char	*line_record(char **s, char **line)
{
	char	*tmp;

	tmp = ft_substr(*s, 0, find_tab(*s));
	*line = ft_strdup(tmp);
	free(tmp);
	return (ft_substr(*s, find_tab(*s) + 1, ft_strlen(*s) - find_tab(*s)));
}

void	free_storage(char **s, char **line)
{
	if (!*s)
	{
		*line = ft_strdup("");
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	*s;
	char		*buff;

	if ((buff = malloc(BUFFER_SIZE + 1)) == NULL)
		return (-1);
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, buff, 0) == -1)
	{
		free(buff);
		return (-1);
	}
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		s = ft_strjoin_to_first(s, buff);
		if (find_tab(s) >= 0)
		{
			s = line_record(&s, line);
			return (1);
		}
	}
	free(buff);
	if (ret == 0)
		free_storage(&s, line);
	return (0);
}
