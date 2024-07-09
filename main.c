/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:50:18 by rachou            #+#    #+#             */
/*   Updated: 2024/07/09 17:23:59 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int		fd;
	int		map_size;
	int		i;
	char	**map;
	char	*line;
	t_data	game;

	//game = NULL;
	fd = open("map/map_2.ber", O_RDONLY);
	if (fd == -1)
		ft_error("ERROR\nMap file opening has failed!\n");
	map_size = INT_MAX;
	map = malloc(sizeof(char *) * map_size);
	if (map == NULL)
		ft_error("ERROR\nMemory allocation has failed!\n");
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (i >= map_size)
		{
			map_size *= 2;//??
			map = realloc(map, sizeof(char *) * map_size);//??
			if (map == NULL)
				ft_error("ERROR\nMemory reallocation has failed!\n");
		}
		map[i] = line;
		i++;
	}
	close(fd);
	map_is_valid(map);
	init_win(&game);
	i--;
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	return (0);
}
