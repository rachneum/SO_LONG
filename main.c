/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:50:18 by rachou            #+#    #+#             */
/*   Updated: 2024/05/31 17:13:37 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"


int	main(void)
{
	int		i;
	int		fd;
	char	*line;
	char	**map = NULL;

	i = 0;
	line = NULL;
	fd = open("maps/map_1.ber", O_RDONLY);
	if (fd == -1)
		error("ERROR: Map file opening failed!\n");
	//init_win();
	line = get_next_line(fd);
	while (line != NULL)
	{
		map = malloc(sizeof(char **));
		map[i] = line;
		i++;
		line = NULL;
	}
	map[i] = NULL;
	close(fd);
	map_valid(map);
	free(map);
	//init_win();
	return (0);
}