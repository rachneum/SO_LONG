/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:50:18 by rachou            #+#    #+#             */
/*   Updated: 2024/06/04 13:38:23 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(void)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;

	i = 0;
	fd = open("maps/map_1.ber", O_RDONLY);
	line = malloc(sizeof(30000000));
	if (fd == -1)
		error("ERROR: Map file opening failed!\n");
	//init_win();
	map = malloc(sizeof(char *) * ft_strlen(line));
	while (fd)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map[i] = line;
		printf("%s", map[i]);
		i++;
	}
	close(fd);
	map_valid(map);
	free(map);
	return (0);
}
