/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:28:53 by rachou            #+#    #+#             */
/*   Updated: 2024/07/11 16:23:59 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(t_data *game)
{
	game->img_pxl = 64;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 600, 500, "so_long");//game->img_pxl *game->x, game->img_pxl *game->y
	get_image_adr(game);
	display_image(game->mlx, game->mlx_win, game, game->map);
	mlx_loop(game->mlx);
}
