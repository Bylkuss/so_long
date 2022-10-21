/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:27:08 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/21 14:20:55 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define X_EVENT_KEY_PRESS 2

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_CLS 17

/*******ERROR MESSAGES*******/

# define WALLS "Your map must be surrounded by walls (1)\n"
# define BADCOMPO "Error! Please insert good map format and try again!\nAt least 1 C, 1 P and 1 E\n"
# define EXTFILE "Map file not accepted. Please enter a .ber file and try again !\n"
# define MAPSIZE "Error, map too big! Please enter a map <= 1080x1920\n"
# define CEBTE "Collect everything before to exit ^_^"
# define ARGSMISS "\nPlease enter a map file after './so_long'\nExemple:\n./so_long map.ber\n"

/**********************************STRUCTS*************************************/
typedef struct s_img
{
	void	*img;
	void	*chara;
	void	*chest;
	void	*land;
	void	*rune;
	void	*wall;
	void	*chara_right;
	void	*chara_left;
	void	*anim;
}			t_img;

typedef struct s_map
{
	void	*mlx;
	void	*win;
	int		nb_movments;
	t_img	img;
	void	*game;
	int		len;
	int		wall_x;
	int		wall_y;
	int		height;
	int		width;
	char	*line;
	char	**map;
	int		p_x;
	int		p_y;
	int		c;
	int		flag;
}			t_map;

void		error_msg(char *msg, int exiit);
void		ft_check_img_file(char *path);
void		map_is_rectangular(int fd, t_map *map);
void		init_game(t_map *map, int fd);
int			map_is_valid(int fd, t_map *map);
int			x_win(void);
void		check_horiz_wall(t_map *map, int height);
void		check_vertical_wall(t_map *map, int width);
void		check_component(char *str, t_map *map);
void		read_map(int fd, t_map *map);
void		valide_map(t_map *map);
void		check_map_file(char *path);
void		free_double(char **tab);
void		init_map(t_map *map);
t_img		img_init(void *mlx);
void		control_img(t_map *map, char c, int i, int j);
void		put_img(t_map *map);
int			validate_move(int keycode, t_map *map);
int			move(int keycode, t_map *map);
void		collecting(t_map *map, int keycode);
void		ft_exit(t_map *map, char *msg, int exiit);
void		check_map(void);
int			press_key(int keycode, t_map *game);


void	back_tracking(t_map *map);
void	print_map(char **map);
void		ft_up(t_map *map);
void		ft_bottom(t_map *map);
void		ft_right(t_map *map);
void		ft_left(t_map *map);

#endif