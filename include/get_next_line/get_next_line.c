/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:45:13 by loadjou           #+#    #+#             */
/*   Updated: 2022/06/27 10:54:14 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_stash(char *stash)
{
	int		i;
	char	*line;
	int		len;
	int		j;

	i = 0;
	len = ft_strlen(stash);
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	line = ft_calloc(sizeof(char), len - i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (stash[++i] != '\0')
		line[j++] = stash[i];
	line[j] = '\0';
	free(stash);
	return (line);
}

char	*get_line(char *stash)
{
	int		i;
	char	*str;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	str = ft_calloc(sizeof(char), i + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, stash, i + 2);
	return (str);
}

char	*ft_read(int fd, char *stash)
{
	char	*buffer;
	int		rd;

	rd = 1;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr1(stash, '\n') == 0 && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		stash = ft_strjoinn(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*str;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (0);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	str = get_line(stash);
	stash = free_stash(stash);
	return (str);
}
