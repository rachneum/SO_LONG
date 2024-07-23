/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:51:03 by rachou            #+#    #+#             */
/*   Updated: 2024/07/23 13:13:31 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>

# define FLOOR_PATH "./assets/stars.xpm"
# define WALL_PATH "./assets/space2.xpm"
# define CHARACTER_FRONT_PATH "./assets/pink_character_front.xpm"
# define CHARACTER_BACK_PATH "./assets/pink_character_back.xpm"
# define CHARACTER_RIGHT_PATH "./assets/pink_character_right.xpm"
# define CHARACTER_LEFT_PATH "./assets/pink_character_left.xpm"
# define COLLECT_PATH "./assets/potion_bottle.xpm"
# define EXIT_DOOR_PATH "./assets/black_hole.xpm"

# define KEY_ESCAPE 53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define KEY_LEFT	123

typedef struct s_img{
	void	*floor;
	void	*wall;
	void	*character_front;
	void	*character_back;
	void	*character_right;
	void	*character_left;
	void	*collectable;
	void	*exit_door;
}	t_img;

typedef struct s_data{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	int		img_pxl;
	int		y;
	int		x;
	int		moves;
	int		collect_points;
	int		total_collect_points;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	t_img	image_adr;
}	t_data;

char	**parse_map(t_data *game, char *file);
char	*ft_strdup(char *s1);
char	**set_map(t_data *game, char *file, int nb_lines);
char	*set_line(t_data *game, char *line, int j);

int		count_lines(char *file);
int 	count_length(char *file);
int		ft_strlen(char *str);
int		count_items(t_data *game, char item);
int		item_is_valid(t_data *game);
int		map_is_closed(t_data *game);
int		map_is_rectangular(t_data *game);
int		key_press(int keycode, t_data *game);
int		red_cross(t_data *data);
int		ft_esc(int keycode, t_data *game);

void	ft_error(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_free_error(char *str, t_data *game);
void	ft_free_map(t_data *game);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	map_is_valid(t_data *game);
void	init_game(t_data *game);
void	get_image_adr(t_data *game);
void	put_floor(t_data *game, int x, int y);
void	put_character(t_data *game, int x, int y, int pos);
void	put_exit(t_data *game, int x, int y);
void	display_image(void *mlx, void *win, t_data *game, char **map);
void	destroy_image(t_data *game);
void	move_player(t_data *game, int x, int y, int pos);

#endif