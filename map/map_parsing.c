/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:48:09 by rachou            #+#    #+#             */
/*   Updated: 2024/07/22 17:28:25 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**set_map(t_data *game, char *file, int nb_lines)//Lit un fichier ligne par ligne, copie chaque ligne dans un tableau de chaînes de caractères map, et renvoie ce tableau.
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
		game->map[i] = strdup(line);//alloue suffisemment de mémoir pour une copie de la string, fait la copie et renvoie un pointeur.
		if (!game->map[i])
			ft_free_error("ERROR\nMalloc has failed!\n", game);
		free(line);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (game->map);
}

char	**parse_map( t_data *game, char *file)
{
	int	nb_lines;

	nb_lines = count_lines(file);
	if (!nb_lines)
		ft_error("ERROR\nThe map is empty!\n");
	game->map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!game->map)
		ft_error("ERROR\nMalloc has failed!\n");
	game->map = set_map(game, file, nb_lines);
	game->x = count_length(file) - 1;
	game->y = nb_lines;
	printf("%d\n%d\n", game->x, game->y);
	return (game->map);
}
