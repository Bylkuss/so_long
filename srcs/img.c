#include "../include/so_long.h"

void	ft_check_img_file(char *img)
{
	int	file;

	file = open(img, O_RDONLY);
	if (file < 0)
	{
		error_msg("xpm file not found!\n", EXIT_FAILURE);
	}
	if (file == 0)
	{
		error_msg("Could not open file\n", EXIT_FAILURE);
	}
}

t_img	img_init(void *mlx)
{
	int		wid;
	int		hei;
	t_img	img;

	img.chara = mlx_xpm_file_to_image(mlx, "assets/idle.xpm", &hei, &wid);
	img.chara_left = mlx_xpm_file_to_image(mlx, "assets/player_left.xpm", &hei, &wid);
	img.chara_right = mlx_xpm_file_to_image(mlx, "assets/player.xpm", &hei, &wid);
	img.land = mlx_xpm_file_to_image(mlx, "assets/void.xpm", &hei, &wid);
	img.wall = mlx_xpm_file_to_image(mlx, "assets/nuage1.xpm", &hei, &wid);
	img.chest = mlx_xpm_file_to_image(mlx, "assets/collectible.xpm", &hei, &wid);
	img.rune = mlx_xpm_file_to_image(mlx, "assets/exit.xpm", &hei, &wid);
	img.anim = mlx_xpm_file_to_image(mlx, "assets/anim.xpm", &hei, &wid);
	return (img);
}

void	put_img(t_map *map)
{
	int			i;
	int			j;
	char		*tmp;
	static int	nb_movments;

	nb_movments = 0;
	j = 0;
	tmp = map->map[j];
	while (tmp)
	{
		i = -1;
		while (tmp[++i])
			control_img(map, tmp[i], i, j);
		j++;
		tmp = map->map[j];
	}
	mlx_string_put(map->mlx, map->window, 62, 60, 0x000000FF, "Moves: ");
	mlx_string_put(map->mlx, map->window, 125, 60, 0x000000FF, ft_itoa(map->nb_movments));
	mlx_string_put(map->mlx, map->window, 300, 60, 0x000000FF, "Collectibles: ");
	mlx_string_put(map->mlx, map->window, 440, 60, 0x000000FF, ft_itoa(map->c));
}

void	control_img(t_map *map, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(map->mlx, map->window, map->img.wall, i * 64, j
				* 64);
	else if (c == 'C')
		mlx_put_image_to_window(map->mlx, map->window, map->img.chest, i * 64, j * 64);
	else if (c == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->window, map->img.land, i * 64, j* 64);
		if(map->flag == 'r')
			mlx_put_image_to_window(map->mlx, map->window, map->img.chara_right, i * 64, j* 64);
		else if(map->flag == 'l')
			mlx_put_image_to_window(map->mlx, map->window, map->img.chara_left, i * 64, j* 64);
		else
			mlx_put_image_to_window(map->mlx, map->window, map->img.chara, i * 64, j* 64);
		map->p_x = i;
		map->p_y = j;
	}
	else if (c == 'E')
		mlx_put_image_to_window(map->mlx, map->window, map->img.rune, i * 64, j
				* 64);
	else
		mlx_put_image_to_window(map->mlx, map->window, map->img.land, i * 64, j
				* 64);
}