/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:48:09 by rachou            #+#    #+#             */
/*   Updated: 2024/08/09 12:26:30 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_map(t_data *game, char *file, int nb_lines)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_free_error("ERROR\nThe map file opening has failed\n", game);
	i = 0;
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
			ft_free_error("ERROR\nMalloc has failed!\n", game);
		game->check_path[i] = ft_strdup(line);
		if (!game->check_path[i])
			ft_free_check_path(game);
		free(line);
		i++;
	}
	game->map[i] = NULL;
	game->check_path[i] = NULL;
	close(fd);
}

void	parse_map(t_data *game, char *file)
{
	int	nb_lines;

	nb_lines = count_lines(file, game);
	if (!nb_lines)
		ft_error("ERROR\nThe map is empty!\n");
	game->map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!game->map)
		ft_free_error("ERROR\nMalloc has failed!\n", game);
	game->check_path = malloc(sizeof(char *) * (nb_lines + 1));
	if (!game->check_path)
		ft_free_check_path(game);
	set_map(game, file, nb_lines);
	game->x = count_length(file, game) - 1;
	game->y = nb_lines;
}
