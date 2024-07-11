/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:48:09 by rachou            #+#    #+#             */
/*   Updated: 2024/07/11 12:13:07 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*char	*set_line(t_data *game, char *line, int j)//Copie le contenu d'une chaîne de caractères line dans une autre chaîne de caractères map, en ignorant les caractères de nouvelle ligne (\n). Elle renvoie ensuite la chaîne de caractères map.
{
	int	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] != '\n')
			game->map[j][i] = line[i];
		else
			break;
		i++;
	}
	game->map[j][i] = '\0';
	return (game->map[i]);
}*/

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
		//game->map[i] = set_line(game, line, i);
		free(line);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (game->map);
}

/*char	**set_map(t_data *game, char *file, int nb_lines)
{
	int	fd;

	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		ft_error("ERROR\nFile opening has failed\n");

}*/

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
	
	return (game->map);
}
