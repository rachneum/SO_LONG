/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:18:01 by rachou            #+#    #+#             */
/*   Updated: 2024/07/16 12:18:46 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_image_adr(t_data *game)
{
	int	width;
	int	height;

	game->image_adr.floor = mlx_xpm_file_to_image(game->mlx, FLOOR_PATH, &width, &height);
	if (!game->image_adr.floor)
		ft_error("ERROR\nGet floor image adr failed\n");
	game->image_adr.wall = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &width, &height);
	if (!game->image_adr.wall)
		ft_error("ERROR\nGet wall image adr failed\n");
	game->image_adr.character = mlx_xpm_file_to_image(game->mlx, CHARACTER_PATH, &width, &height);
	if (!game->image_adr.character)
		ft_error("ERROR\nGet character image adr failed\n");
	game->image_adr.collectable = mlx_xpm_file_to_image(game->mlx, COLLECT_PATH, &width, &height);
	if (!game->image_adr.collectable)
		ft_error("ERROR\nGet collectable image adr failed\n");
}
