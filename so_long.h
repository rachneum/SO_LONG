/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:23:47 by rachou            #+#    #+#             */
/*   Updated: 2024/07/08 15:08:38 by rachou           ###   ########.fr       */
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

char	**parse_map(char *map_file);
char	**set_map(char **map, char *file, int nb_lines);
char	*set_line(char *map, char *line);

int		count_lines(char *file);
int		ft_strlen(char *str);
int		map_is_rectangular(char **map);
int		map_is_closed(char **map);
int		item_is_valid(char **map);
int		count_items(char **map, char item);

void	ft_error(char *str);
void    ft_putstr_fd(char *str, int fd);
void	map_is_valid(char **map);
void	ft_free_error(char *str, char **map);
void	ft_free_map(char **map);

#endif