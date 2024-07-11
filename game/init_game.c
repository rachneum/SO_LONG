/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:28:53 by rachou            #+#    #+#             */
/*   Updated: 2024/07/11 13:42:41 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(t_data *game)
{
	game->img_pxl = 64;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 600, 600, "so_long");//game->img_pxl *game->x, game->img_pxl *game->y
	mlx_loop(game->mlx);
}
