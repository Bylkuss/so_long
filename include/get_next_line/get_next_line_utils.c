/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:47:55 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/21 19:12:51 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr1(char *str, int c)
{
	if (!str)
		return (0);
	if (c == '\0')
		return (1);
	while (*str)
		if (*(str++) == (char)c)
			return (1);
	return (0);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	char	*str;
	size_t	i;

	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free (s1);
	return (str);
}
