/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:53:21 by youssama          #+#    #+#             */
/*   Updated: 2021/12/12 19:59:20 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_all(int fd, char *text)
{
	ssize_t	i;
	char	*line;

	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	i = 1;
	while (!(ft_strchr(text, '\n')) && i != 0)
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return (NULL);
		}
		line[i] = '\0';
		text = ft_strjoin(text, line);
	}
	free(line);
	return (text);
}

char	*get_line(char *text)
{
	char	*line;
	size_t	len;
	size_t	j;

	len = 0;
	j = 0;
	if (text[0] == '\0')
		return (NULL);
	while (text[len] != '\n' && text[len] != '\0')
		len++;
	if (text[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (0);
	while (j < len)
	{
		line[j] = text[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*new_txt(char *text)
{
	char	*newtxt;
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	while (text[k] != '\n' && text[k] != '\0')
		k++;
	if (!text[k])
	{
		free(text);
		return (NULL);
	}
	newtxt = (char *)malloc(ft_strlen(text) - k + 1);
	if (!newtxt)
		return (0);
	while (text[k++])
		newtxt[i++] = text[k];
	newtxt[i] = '\0';
	free(text);
	return (newtxt);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text = read_all(fd, text);
	if (!text)
		return (NULL);
	line = get_line(text);
	text = new_txt(text);
	return (line);
}
