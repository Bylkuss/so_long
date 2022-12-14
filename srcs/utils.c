/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 08:49:34 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/21 18:36:26 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_msg(char *msg, int exiit)
{
	ft_putstr_fd(msg, 2);
	exit(exiit);
}

void	player_pos(t_map *map)
{
	int	y;

	y = 0;
	while (map->map[y])
	{
		if (ft_strchr(map->map[y], 'P'))
		{
			map->p_x = ft_strchr(map->map[y], 'P') - map->map[y] + 1;
			map->p_y = y + 1;
			return ;
		}
		y++;
	}
}

char	**copy_map(t_map *map)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_calloc(sizeof(char *), map->height + 1);
	if (!temp)
		return (NULL);
	while (i < map->height)
	{
		temp[i] = ft_strdup(map->map[i]);
		i++;
	}
	return (temp);
}

void	ride_map(char **map, int x, int y)
{
	if (ft_strchr("E0C", map[y + 1][x]))
	{
		map[y + 1][x] = 'f';
		ride_map(map, x, y + 1);
	}
	if (ft_strchr("E0C", map[y - 1][x]))
	{
		map[y - 1][x] = 'f';
		ride_map(map, x, y - 1);
	}
	if (ft_strchr("E0C", map[y][x + 1]))
	{
		map[y][x + 1] = 'f';
		ride_map(map, x + 1, y);
	}
	if (ft_strchr("E0C", map[y][x - 1]))
	{
		map[y][x - 1] = 'f';
		ride_map(map, x - 1, y);
	}
	return ;
}

void	back_tracking(t_map *map)
{
	char	**temp;
	int		i;
	int		j;

	temp = copy_map(map);
	player_pos(map);
	ride_map(temp, map->p_x, map->p_y);
	j = -1;
	while (temp[++j])
	{
		i = 0;
		while (temp[j][i])
		{
			if (temp[j][i] == 'E' || temp[j][i] == 'C')
			{
				free_double(temp);
				error_msg("No path to exit\n", 0);
			}
			i++;
		}
	}
	free_double(temp);
}
