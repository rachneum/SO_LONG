/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:46:21 by rachou            #+#    #+#             */
/*   Updated: 2024/07/16 12:40:36 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*void	put_exit(t_data *game, int x, int y)
{
	void	*mlx;
	void	*mlx_win;

	mlx = game->mlx;
	mlx_win = game->mlx_win;

}*/

void	put_character(t_data *game, int x, int y)
{
	void	*mlx;
	void	*mlx_win;

	mlx = game->mlx;
	mlx_win = game->mlx_win;
	mlx_put_image_to_window(mlx, mlx_win, game->image_adr.character, 64 * x, 64 * y);

}

void	put_floor(t_data *game, int x, int y)
{
	void	*mlx;
	void	*mlx_win;

	mlx = game->mlx;
	mlx_win = game->mlx_win;
	mlx_put_image_to_window(mlx, mlx_win, game->image_adr.floor, 64 * x, 64 * y);
}

void	display_image(void *mlx, void *mlx_win, t_data *game, char **map)
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
				mlx_put_image_to_window(mlx, mlx_win, game->image_adr.wall, 64 * x, 64 * y);
			else if (map[y][x] == 'P')
				put_character(game, x, y);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, game->image_adr.collectable, 64 * x, 64 * y);
			x++;
		}
		y++;
	}
}
