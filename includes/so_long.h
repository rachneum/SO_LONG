/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:19:59 by rachou            #+#    #+#             */
/*   Updated: 2024/05/29 17:13:57 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

# define BACKGROUND_PATH "../assets/background.xpm"
# define BUSHES_PATH "../assets/bushes.xpm"
# define FLOWERS_PATH "../assets/flowers.xpm"
# define TREES_PATH "../assets/bushes.xpm"

typedef struct s_data
{
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	map_valid(char **map);
void	free_map(char **map);
void	error(char *str);
void	free_error(char *str, char **map);
void	init_win(void);

char	**parse_map(char *file);

int ft_strlen(char *str);

#endif