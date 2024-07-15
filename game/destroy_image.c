/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:55:49 by rachou            #+#    #+#             */
/*   Updated: 2024/07/15 13:09:08 by rachou           ###   ########.fr       */
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
	if (game->image_adr.character)
		mlx_destroy_image(mlx, game->image_adr.character);
}
