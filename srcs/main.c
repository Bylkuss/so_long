/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:26:42 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/21 19:17:40 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_double(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void	ft_exit(t_map *map, char *msg, int exiit)
{
	free_double(map->map);
	ft_putstr_fd(msg, 2);
	exit(exiit);
}

void	init_map(t_map *map)
{
	map->nb_movments = 0;
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

	if (argc == 2)
	{
		check_map_file(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			error_msg("File doesn't exit.\n", EXIT_FAILURE);
		init_map(&map);
		init_game(&map, fd);
		free_double(map.map);
	}
	else
		error_msg(ARGSMISS, EXIT_FAILURE);
	return (0);
}
