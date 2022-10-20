/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:47:55 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/13 15:35:00 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	char	*tab;
// 	int		i;

// 	i = 0;
// 	tab = malloc(nmemb * size);
// 	if (!tab)
// 		return (NULL);
// 	if (size == SIZE_MAX)
// 		return (NULL);
// 	while (tab[i])
// 		tab[i++] = '\0';
// 	return (tab);
// }

// int	ft_strlen(char *str)
// {
// 	unsigned long	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

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
	return (str);
}

// size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
// {
// 	size_t	len;

// 	len = ft_strlen(src);
// 	if (dstsize == 0)
// 		return (len);
// 	while (*src && --dstsize)
// 		*dst++ = *src++;
// 	*(dst) = '\0';
// 	return (len);
// }
