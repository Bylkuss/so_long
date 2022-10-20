/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:36:08 by loadjou           #+#    #+#             */
/*   Updated: 2022/06/23 13:26:27 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
// void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strchr1(char *str, int c);
// void	ft_bzero(void *s, size_t n);
// char	*ft_substr(char *s, unsigned int start, size_t len);
// int		ft_strlen(char *str);
char	*ft_strjoinn(char *s1, char *s2);
// size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif
