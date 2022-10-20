/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:18:25 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/20 16:18:36 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_file(char *path)
{
	if (!(ft_strnstr(&path[(int)ft_strlen(path) - 4], ".ber", 5)))
		error_msg("Map file not accepted. Please enter a .ber file and try again !\n",
					EXIT_FAILURE);
}

int	check_wall_up(t_map *map)
{
	while (map->map[map->wall_y][map->wall_y])
	{
		if (map->map[map->wall_y][map->wall_x] == '1')
			map->wall_x++;
		else
			return (0);
	}
	map->wall_x--;
	return (1);
}

void	check_vertical_wall(t_map *map, int width)
{
	int	i;
	int	j;

	width = 0;
	i = 0;
	j = (int)ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if (map->map[i][0] != '1' || map->map[i][j - 1] != '1')
			error_msg("Your map must be surrounded by walls (1) Vert\n",
						EXIT_FAILURE);
		i++;
	}
}

void	check_horiz_wall(t_map *map, int height)
{
	int	i;

	i = 0;
	while (map->map[height][i])
	{
		if (map->map[height][i] != '1')
			error_msg("Your map must be surrounded by walls (1)\n",
						EXIT_FAILURE);
		i++;
	}
}

void	check_component(char *str, t_map *map)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	map->c = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			map->c++;
		else if (str[i] == 'E')
			e++;
		else if (str[i] == 'P')
			p++;
		i++;
	}
	if (map->c < 1 || p != 1 || e != 1)
		error_msg("Error! Please insert good map format and try again!\nAt least 1 C, 1 P and 1 E\n", EXIT_FAILURE);
}

void	check_map(void)
{
	ft_check_img_file("assets/idle.xpm");
	ft_check_img_file("assets/player.xpm");
	ft_check_img_file("assets/player_left.xpm");
	ft_check_img_file("assets/void.xpm");
	ft_check_img_file("assets/nuage1.xpm");
	ft_check_img_file("assets/collectible.xpm");
	ft_check_img_file("assets/exit.xpm");
}
