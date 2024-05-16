/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:02:30 by rachou            #+#    #+#             */
/*   Updated: 2024/05/16 16:46:58 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long"

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("ERROR: Map file opening failed!\n");
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		count++;
		free(line);
	}
	return (count);
}

static char	**set_map_data(char **map, char *file, int nb_lines)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_error("ERROR: Map file opening failed\n", map);
	i = 0;
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!map[i])
			free_error("ERROR: Malloc failed!\n", map);
		map[i] = set_line_data(map[i], line);
		free(line);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

static char	*set_line_data(char *map, char *line)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[x] != '\n')
			map[i] = line[i];
		else
			break;
		i++;
	}
	map[i] = '\0';
	return (map);
}

char	**parse_map(char *file)
{
	char	**map;
	int		nb_lines;

	nb_lines = count_lines(file);
	if (!nb_lines)
		error("ERROR: Map file is empty\n");
	map = malloc(sieof(char *) * (nb_lines + 1));
	if (!map)
		error("ERROR: Malloc failed!\n");
	map = set_map_data(map, file, nb_lines);
	map_valid(map);
	return (map);

}