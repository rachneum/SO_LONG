/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:46:21 by rachou            #+#    #+#             */
/*   Updated: 2024/07/15 13:47:32 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*void	put_character(t_data *game, int x, int y)
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
}*/

void	display_image(void *mlx, void *mlx_win, t_data *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		printf("Placing wall at %d, %d\n", x, y);
		while (map[y][x])
		{
			mlx_put_image_to_window(mlx, mlx_win, game->image_adr.floor, 64 * x, 64 * y);
			//put_floor(game, x, y);
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, game->image_adr.wall, 64 * x, 64 * y);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, game->image_adr.character, 64 * x, 64 * y);
			x++;
		}
		y++;
	}
}

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
}
