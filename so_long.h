/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:51:03 by rachou            #+#    #+#             */
/*   Updated: 2024/07/11 13:42:31 by rachou           ###   ########.fr       */
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

# define FLOOR_PATH "./assets/floor.xpm"

typedef struct s_data{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	int		img_pxl;
	//int		x;
	//int		y;
}	t_data;

char	**parse_map(t_data *game, char *file);
char	**set_map(t_data *game, char *file, int nb_lines);
char	*set_line(t_data *game, char *line, int j);

int		count_lines(char *file);
int		ft_strlen(char *str);
int		count_items(t_data *game, char item);
int		item_is_valid(t_data *game);
//int		map_is_closed(t_data *game);
int		map_is_rectangular(t_data *game);

void	ft_error(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_free_error(char *str, t_data *game);
void	ft_free_map(t_data *game);
void	map_is_valid(t_data *game);
void	init_game(t_data *game);

#endif