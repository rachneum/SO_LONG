/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:46:21 by rachou            #+#    #+#             */
/*   Updated: 2024/08/01 14:15:48 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_exit(t_data *game, int x, int y)
{
	void	*mlx;
	void	*mlx_win;

	mlx = game->mlx;
	mlx_win = game->mlx_win;
	mlx_put_image_to_window(mlx, mlx_win,
		game->image_adr.exit_door, (64 * x) + 12, (64 * y) + 12);
}

void	put_character(t_data *game, int x, int y, int pos)
{
	void	*mlx;
	void	*mlx_win;

	mlx = game->mlx;
	mlx_win = game->mlx_win;
	if (pos == 0)
		mlx_put_image_to_window(mlx, mlx_win,
			game->image_adr.character_front, (64 * x) + 12, (64 * y) + 12);
	if (pos == 1)
		mlx_put_image_to_window(mlx, mlx_win,
			game->image_adr.character_back, (64 * x) + 12, (64 * y) + 12);
	if (pos == 2)
		mlx_put_image_to_window(mlx, mlx_win,
			game->image_adr.character_right, (64 * x) + 12, (64 * y) + 12);
	if (pos == 3)
		mlx_put_image_to_window(mlx, mlx_win,
			game->image_adr.character_left, (64 * x) + 12, (64 * y) + 12);
	game->player_x = x;
	game->player_y = y;
}

void	put_floor(t_data *game, int x, int y)
{
	void	*mlx;
	void	*mlx_win;

	mlx = game->mlx;
	mlx_win = game->mlx_win;
	mlx_put_image_to_window(mlx, mlx_win,
		game->image_adr.floor, 64 * x, 64 * y);
}

void	display_image(t_data *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			put_floor(game, x, y);
			if (map[y][x] == '1')
				put_wall(game, x, y);
			else if (map[y][x] == 'P')
				put_character(game, x, y, 0);
			else if (map[y][x] == 'C')
				put_collectable(game, x, y);
			else if (map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
			}
			x++;
		}
		y++;
	}
}
