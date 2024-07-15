/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:28:53 by rachou            #+#    #+#             */
/*   Updated: 2024/07/15 14:11:27 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(t_data *game)
{
	game->img_pxl = 64;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 831, 330, "so_long");
	get_image_adr(game);
	display_image(game->mlx, game->mlx_win, game, game->map);
	mlx_hook(game->mlx_win, 17, 0, &red_cross, game);//17 = hooking event: ON_DESTROY
	mlx_hook(game->mlx_win, 2, 0, &key_press, game);//2 = hooking event: ON_KEYDOWN
	mlx_loop(game->mlx);
}
