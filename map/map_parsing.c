/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:02:30 by rachou            #+#    #+#             */
/*   Updated: 2024/07/09 14:34:31 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*set_line(char *map, char *line)//Copie le contenu d'une chaîne de caractères line dans une autre chaîne de caractères map, en ignorant les caractères de nouvelle ligne (\n). Elle renvoie ensuite la chaîne de caractères map.
{
	int	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] != '\n')
			map[i] = line[i];
		else
			break;
		i++;
	}
	map[i] = '\0';
	return (map);
}

char	**set_map(char **map, char *file, int nb_lines)//Lit un fichier ligne par ligne, copie chaque ligne dans un tableau de chaînes de caractères map, et renvoie ce tableau.
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_free_error("ERROR\nMap file opening has failed\n", map);
	i = 0;
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!map[i])
			ft_free_error("ERROR\nMalloc has failed!\n", map);
		map[i] = set_line(map[i], line);
		free(line);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**parse_map(char *map_file)
{
	int		nb_lines;
	char	**map;

	nb_lines = count_lines(map_file);
	if (!nb_lines)
		ft_error("ERROR\nMap is empty!\n");
	map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!map)
		ft_error("ERROR\nMalloc has failed!\n");
	map = set_map(map, map_file, nb_lines);
	map_is_valid(map);
	return (map);
}
