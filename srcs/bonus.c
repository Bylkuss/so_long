/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:53:18 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/21 14:51:14 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
/*
static int find_line(t_map *map)
{
    int y = 1;
    int x = 1;
    while(y < map->height)
    {
        while(map->map[y][x] != '1' && map->map[y][x] == '0')
        {
            if(x == map->width)
                return y;
            x++;
        }
        y++;
    }
    return 0;
}


void    make_ennemy(t_map *map)
{
    // int y = find_line(map);
    int x = 1;
    // if(y)
    // {
        while(map->map[5][x] && x < map->width)
        {
            // mlx_put_image_to_window(map->mlx, map->window, map->img.land, x 
                * 64, 5 * 64);
            mlx_put_image_to_window(map->mlx, map->win, map->img.anim, x 
                * 64, 5 * 64);
            // usleep(25000);
            // mlx_put_image_to_window(map->mlx, map->window, map->img.land, 
                x * 64, 5 * 64);
            x++;
            // usleep(25000);
        }
    // }
}
*/
