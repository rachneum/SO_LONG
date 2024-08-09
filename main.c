/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:52:30 by rachou            #+#    #+#             */
/*   Updated: 2024/08/09 12:36:24 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		ft_error("ERROR\nThere is not the right amount of arguments!\n");
	parse_map(&game, argv[1]);
	map_is_valid(&game);
	init_game(&game);
	return (0);
}
