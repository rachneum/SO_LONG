/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:52:30 by rachou            #+#    #+#             */
/*   Updated: 2024/08/14 14:10:00 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	game;
	int		len;

	if (argc != 2)
		ft_error("ERROR\nThere is not the right amount of arguments!\n");
	len = ft_strlen(argv[1]);
	if ((ft_strncmp(argv[1] + len - 4, ".ber", 4)) != 0)
		ft_error("ERROR\nMap format is invalid!\n");
	parse_map(&game, argv[1]);
	map_is_valid(&game);
	init_game(&game);
	return (0);
}
