/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:14:22 by raneuman          #+#    #+#             */
/*   Updated: 2024/07/31 15:19:57 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_wall(t_data *game, int x, int y)
{
	void	*mlx;
	void	*mlx_win;

	mlx = game->mlx;
	mlx_win = game->mlx_win;
	mlx_put_image_to_window(mlx, mlx_win,
		game->image_adr.wall, 64 * x, 64 * y);
}

void	put_collectable(t_data *game, int x, int y)
{
	void	*mlx;
	void	*mlx_win;

	mlx = game->mlx;
	mlx_win = game->mlx_win;
	mlx_put_image_to_window(mlx, mlx_win,
		game->image_adr.collectable, (64 * x) + 12, (64 * y) + 12);
}
