/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:50:18 by rachou            #+#    #+#             */
/*   Updated: 2024/06/05 15:47:46 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(void)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;
	int		map_size;

	i = 0;
	fd = open("maps/map_2.ber", O_RDONLY);
	if (fd == -1)
		error("ERROR: Map file opening failed!\n");
	map_size = 100;
	map = malloc(sizeof(char *) * map_size);
	if (map == NULL)
		error("ERROR: Memory allocation failed!\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		if (i >= map_size)
		{
			map_size *= 2;
			map = realloc(map, sizeof(char *) * map_size);
			if (map == NULL)
				error("ERROR: Memory reallocation failed!\n");
		}
		map[i] = line;
		i++;
	}
	//map[i] = NULL;
	close(fd);
	map_valid(map);
	init_win();
	i--;
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	return (0);
}
