/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:26:42 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/19 18:49:23 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	map->wall_x = 0;
	map->wall_y = 0;
	map->width = 0;
	map->height = 0;
	map->c = 0;
	map->line = NULL;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	// t_game game;
	if (argc == 2)
	{

		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			error_msg("File doesn't exit.\n", EXIT_FAILURE);
		init_map(&map);
		init_game(&map, fd);
	}
	else
		error_msg("\nPlease enter a map file after './so_long'\nExemple:\n./so_long map.ber\n",
				EXIT_FAILURE);
	return (0);
}