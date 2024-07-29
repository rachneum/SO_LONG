/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:28:14 by rachou            #+#    #+#             */
/*   Updated: 2024/07/29 16:47:39 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*void	set_map_copy(t_data *game, char *file, int nb_lines)//Lit un fichier ligne par ligne, copie chaque ligne dans un tableau de chaînes de caractères map, et renvoie ce tableau.
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_free_error_2("ERROR\nThe map file opening has failed\n", game);
	i = 0;
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		game->check_path[i] = ft_strdup(line);//Alloue suffisemment de mémoir pour une copie de la string, fait la copie et renvoie un pointeur.
		if (!game->check_path[i])
			ft_free_error_2("ERROR\nMalloc has failed!\n", game);
		free(line);
		i++;
	}
	game->check_path[i] = NULL;
	close(fd);
}

void	map_copy(t_data *game, char *file)
{
	int	nb_lines;

	nb_lines = count_lines(file);
	if (!nb_lines)
		ft_error("ERROR\nThe map is empty!\n");
	game->check_path = malloc(sizeof(char *) * (nb_lines + 1));
	if (!game->check_path)
		ft_error("ERROR\nMalloc has failed!\n");
	set_map_copy(game, file, nb_lines);
}*/
