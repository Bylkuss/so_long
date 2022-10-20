/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 08:49:34 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/20 11:11:33 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_msg(char *msg, int exiit)
{
	ft_putstr_fd(msg, 2);
	exit(exiit);
}
void	free_double(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	find_player(t_map *map)
{
	int i;
	int j = 0;
	while(map->map[j])
	{
		i = 0;
		while(map->map[j][i] && map->map[j][i] != 'P')
				i++;
		j++;
	}
	map->p_x = i;
	map->p_y = j;
}

char	**copy_map(t_map *map)
{
	char **temp;
	int i = 0;

	printf("map->p_x %d\n", map->p_x);
	temp = ft_calloc(sizeof(char *), map->height) + 1;
	while(i < map->height)
	{
		temp[i] = ft_strdup(map->map[i]);
		printf("%s\n", temp[i]);
		printf("i = %d\n", i);
		i++;
	}
	return temp;
}

void	ride_map(char **map, int x, int y)
{
	

		if(map[y + 1][x] != '1')
		{
			map[y + 1][x] = 'f';
			ride_map(map, x, y + 1);
		}
		if(map[y - 1][x] != '1')
		{
			map[y - 1][x] = 'f';
			ride_map(map, x, y - 1);
		}
		if(map[y][x + 1] != '1')
		{
			map[y][x + 1] = 'f';
			ride_map(map, x + 1, y);
		}
		if(map[y][x - 1] != '1')
		{
			map[y][x - 1] = 'f';
			ride_map(map, x - 1, y);
		}
	return ;
}

void	back_tracking(t_map *map)
{
	char **temp;
	find_player(map);
	temp = copy_map(map);
	ride_map(temp, map->p_x, map->p_y);
	int i = 0;
	int j = -1;
	while(temp[++j])
	{
		while(temp[j][i])
		{
			if(temp[j][i] == 'E')
				error_msg("No path to exit\n", 0);
			i++;
		}
	}
}