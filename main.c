/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:21:34 by rachou            #+#    #+#             */
/*   Updated: 2024/07/08 15:40:40 by rachou           ###   ########.fr       */
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

	fd = open("maps/map_1.ber", O_RDONLY);
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
