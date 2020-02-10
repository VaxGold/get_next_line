/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:54:27 by omercade          #+#    #+#             */
/*   Updated: 2020/02/07 15:24:33 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen((char *)s) == 0)
		return (ft_strdup(""));
	if (ft_strlen((char *)s) < (size_t)start)
		return (ft_strdup(""));
	if ((str = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i] != 0)
	{
		*(str + i) = *((char *)s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if ((str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	if (((unsigned char *)dst == 0 && (unsigned char *)src == 0)
			|| (dst == src))
		return (NULL);
	temp = (unsigned char*)dst;
	if ((unsigned char *)src < temp)
	{
		while (len > 0)
		{
			len--;
			temp[len] = *((unsigned char *)src + len);
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			temp[i] = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ptr;

	len = ft_strlen((char *)s1);
	if ((ptr = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memmove(ptr, (char *)s1, len);
	ptr[len] = '\0';
	return (ptr);
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}
