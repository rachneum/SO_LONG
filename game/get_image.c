/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:18:01 by rachou            #+#    #+#             */
/*   Updated: 2024/07/16 13:31:26 by rachou           ###   ########.fr       */
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
	game->image_adr.character_front = mlx_xpm_file_to_image(game->mlx, CHARACTER_FRONT_PATH, &width, &height);
	if (!game->image_adr.character_front)
		ft_error("ERROR\nGet character image adr failed\n");
	game->image_adr.character_back = mlx_xpm_file_to_image(game->mlx, CHARACTER_BACK_PATH, &width, &height);
	if (!game->image_adr.character_back)
		ft_error("ERROR\nGet character image adr failed\n");
	game->image_adr.character_right = mlx_xpm_file_to_image(game->mlx, CHARACTER_RIGHT_PATH, &width, &height);
	if (!game->image_adr.character_right)
		ft_error("ERROR\nGet character image adr failed\n");
	game->image_adr.character_left = mlx_xpm_file_to_image(game->mlx, CHARACTER_LEFT_PATH, &width, &height);
	if (!game->image_adr.character_left)
		ft_error("ERROR\nGet character image adr failed\n");
	game->image_adr.collectable = mlx_xpm_file_to_image(game->mlx, COLLECT_PATH, &width, &height);
	if (!game->image_adr.collectable)
		ft_error("ERROR\nGet collectable image adr failed\n");
}
