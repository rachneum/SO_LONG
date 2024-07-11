/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:52:30 by rachou            #+#    #+#             */
/*   Updated: 2024/07/11 12:32:29 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	game;
	int i = -1;

	if (argc != 2)
		ft_error("ERROR\nThere is not the right amount of arguments!\n");
	parse_map(&game, argv[1]);
	while (game.map[++i])
		printf("%s", game.map[i]);
	map_is_valid(&game);
	//init_game(&game);
	return (0);
}
