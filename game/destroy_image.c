/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:55:49 by rachou            #+#    #+#             */
/*   Updated: 2024/07/16 16:00:45 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_image(t_data *game)
{
	void	*mlx;

	mlx = game->mlx;
	if (game->image_adr.floor)
		mlx_destroy_image(mlx, game->image_adr.floor);
	if (game->image_adr.wall)
		mlx_destroy_image(mlx, game->image_adr.wall);
	if (game->image_adr.character_front)
		mlx_destroy_image(mlx, game->image_adr.character_front);
	if (game->image_adr.character_back)
		mlx_destroy_image(mlx, game->image_adr.character_back);
	if (game->image_adr.character_right)
		mlx_destroy_image(mlx, game->image_adr.character_right);
	if (game->image_adr.character_left)
		mlx_destroy_image(mlx, game->image_adr.character_left);
	if (game->image_adr.exit_door)
		mlx_destroy_image(mlx, game->image_adr.exit_door);
}
