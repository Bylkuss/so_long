/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:12:02 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/21 19:26:57 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_map *map, int fd)
{
	map->mlx = mlx_init();
	map->img = img_init(map->mlx);
	read_map(fd, map);
	valide_map(map);
	check_map();
	back_tracking(map);
	if (map->width * 64 <= 1920 && map->height * 64 <= 1080)
	{
		map->nb_movments = 0;
		map->win = mlx_new_window(map->mlx, map->width * 64, map->height * 64,
				"SO_LONG");
		put_img(map);
		mlx_hook(map->win, 2, 1L << 0, press_key, map);
		mlx_hook(map->win, 17, X_EVENT_KEY_PRESS, x_win, map);
		mlx_loop(map->mlx);
	}
	else
		error_msg(MAPSIZE, EXIT_FAILURE);
}

int	x_win(void)
{
	exit(0);
}
