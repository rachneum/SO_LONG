/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:50:18 by rachou            #+#    #+#             */
/*   Updated: 2024/05/29 17:02:30 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"


int	main(void)
{
	int		i;
	int		fd;
	char	**map;
	char	*line;

	i = 0;
	fd = open("maps/map_1.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	//init_win();
	map = (char **)malloc(sizeof(char *));
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	map_valid(map);
	init_win();
	return (0);
}