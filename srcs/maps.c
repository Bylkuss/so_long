/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:39:06 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/19 18:48:23 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(char **map)
{
	int i = -1;
	while(map[++i])
		printf("%s\n", map[i]);
}

void	read_map(int fd, t_map *map)
{
	char *temp;
	temp =	get_next_line(fd);
	if(!temp)
		error_msg("Your file's empty!\n", EXIT_FAILURE);
	map->width = (int)ft_strlen(temp) - 1;
	map->height = 0;
	while(temp)
	{
		if(map->line)
			map->line = ft_strjoin(map->line, temp);
		else
			map->line = ft_strdup(temp);
		free(temp);
		temp =	get_next_line(fd);
		map->height++;
	}
	check_component(map->line, map);
	map->map = ft_split(map->line, '\n');
	close(fd);
	}


void valide_map(t_map *map)
{
	check_horiz_wall(map, 0);
	check_horiz_wall(map, map->height - 1);
	check_vertical_wall(map, map->width - 1);
	// printf("width: %d", map->width);
}


int	map_is_valid(int fd, t_map *map)
{
	if (!map || fd < 0)
		return (0);
	// if (!(check_wall_up(map)))
	// 	error_msg("Error! Walls mustn't be close\n", EXIT_FAILURE);

	return (1);
}

