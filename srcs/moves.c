/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:23:05 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/20 11:45:45 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

void    ft_up(t_map *map)
{
    map->flag = 'i';
    if(map->map[map->p_y - 1][map->p_x] != '1' && map->map[map->p_y - 1][map->p_x] != 'E')
    {
        map->nb_movments++;
        printf("moves: %d\n", map->nb_movments);
        if(map->map[map->p_y - 1][map->p_x] == 'C')
            map->c--;
        map->map[map->p_y - 1][map->p_x] = 'P';
        map->map[map->p_y][map->p_x] = '0';
    }
    put_img(map);
    
    if(map->map[map->p_y - 1][map->p_x] == 'E')
    {
        if(map->c == 0)
            exit(0);
        else
            mlx_string_put(map->mlx, map->window, 100, 100, 0x00FF0000, "Collect everything before to exit ^_^");
    }
}

void    ft_right(t_map *map)
{
    map->flag = 'r';
    if(map->map[map->p_y][map->p_x + 1] != '1' && map->map[map->p_y][map->p_x + 1] != 'E')
    {
        map->nb_movments++;
        printf("moves: %d\n", map->nb_movments);
        if(map->map[map->p_y][map->p_x + 1] == 'C')
            map->c--;
        map->map[map->p_y][map->p_x] = '0';
        map->map[map->p_y][map->p_x + 1] = 'P';
    }
    put_img(map);
    if(map->map[map->p_y][map->p_x + 1] == 'E')
    {
        if(map->c == 0)
            exit(0);
        else
            mlx_string_put(map->mlx, map->window, 100, 100, 0x00FF0000, "Collect everything before to exit ^_^");
    }
}

void    ft_bottom(t_map *map)
{
    map->flag = 'i';
    if(map->map[map->p_y + 1][map->p_x] != '1' && map->map[map->p_y + 1][map->p_x] != 'E')
    {
        map->nb_movments++;
        printf("moves: %d\n", map->nb_movments);
        if(map->map[map->p_y + 1][map->p_x] == 'C')
            map->c--;
        map->map[map->p_y][map->p_x] = '0';
        map->map[map->p_y + 1][map->p_x] = 'P';
    }
    put_img(map);
    if(map->map[map->p_y + 1][map->p_x] == 'E')
    {
        if(map->c == 0)
            exit(0);
        else
            mlx_string_put(map->mlx, map->window, 100, 100, 0x00FF0000, "Collect everything before to exit ^_^");
    }
}

void    ft_left(t_map *map)
{
    map->flag = 'l';
    if(map->map[map->p_y][map->p_x - 1] != '1' && map->map[map->p_y][map->p_x - 1] != 'E')
    {
        map->nb_movments++;
        printf("moves: %d\n", map->nb_movments);
        if(map->map[map->p_y][map->p_x - 1] == 'C')
            map->c--;
        map->map[map->p_y][map->p_x] = '0';
        map->map[map->p_y][map->p_x - 1] = 'P';
    }
    put_img(map);
    if(map->map[map->p_y][map->p_x - 1] == 'E')
    {
        if(map->c == 0)
            exit(0);
        else
            mlx_string_put(map->mlx, map->window, 100, 100, 0x00FF0000, "Collect everything before to exit ^_^");
    }
}


int	press_key(int keycode, t_map *game)
{
	if (keycode == KEY_ESC)
        exit(0);
	else if (keycode == KEY_W || keycode == 126)
		ft_up(game);
	else if (keycode == KEY_D || keycode == 124)    
		ft_right(game);
	else if (keycode == KEY_S || keycode == 125)
		ft_bottom(game);
	else if (keycode == KEY_A || keycode == 123)
		ft_left(game);
	return (0);
}
