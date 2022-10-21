/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:18:25 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/21 14:51:52 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_file(char *path)
{
	if (!(ft_strnstr(&path[(int)ft_strlen(path) - 4], ".ber", 5)))
		error_msg(EXTFILE, EXIT_FAILURE);
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
			ft_exit(map, WALLS, EXIT_FAILURE);
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
			ft_exit(map, WALLS, EXIT_FAILURE);
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
		if (!ft_strchr("1E0PEC\n", str[i]))
			error_msg(BADCOMPO, 0);
		if (str[i] == 'C')
			map->c++;
		else if (str[i] == 'E')
			e++;
		else if (str[i] == 'P')
			p++;
		i++;
	}
	if (map->c < 1 || p != 1 || e != 1)
		ft_exit(map, BADCOMPO, EXIT_FAILURE);
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
