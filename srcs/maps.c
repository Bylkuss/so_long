/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:39:06 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/21 17:39:26 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	is_rectangular(t_map *map)
{
	int	i;
	int	w;

	i = 0;
	while (i < map->height)
	{
		w = ft_strlen(map->map[i]);
		if (w != map->width)
			error_msg("map must be rectangular\n", 0);
		i++;
	}
}

void	valide_map(t_map *map)
{
	// printf("height %d width %d\n", map->height, map->width);
	// print_map(map->map);
	is_rectangular(map);
	check_horiz_wall(map, 0);
	check_horiz_wall(map, map->height - 1);
	check_vertical_wall(map, 0);
	check_vertical_wall(map, map->width - 1);
}

void	read_map(int fd, t_map *map)
{
	char	*temp;

	temp = get_next_line(fd);
	if (!temp)
		error_msg("Your file's empty!\n", EXIT_FAILURE);
	map->width = (int)ft_strlen(temp) - 1;
	map->height = 0;
	while (temp)
	{
		map->height++;
		if (map->line)
			map->line = ft_strjoin(map->line, temp);
		else
			map->line = ft_strdup(temp);
		free(temp);
		temp = get_next_line(fd);
	}
	check_component(map->line, map);
	map->map = ft_split(map->line, '\n');
	free(map->line);
	close(fd);
}
