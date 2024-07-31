/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:28:53 by rachou            #+#    #+#             */
/*   Updated: 2024/07/31 12:38:29 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_pos(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (game->map[y][x] == 'P')
			{
				game->copy_player_y = y;
				game->copy_player_x = x;
			}
			x++;
		}
		y++;
	}
}

int	valid_cross(t_data *game, int x, int y)//M'assure de ne pas dépasser les limites de ma map.
{
	if (x < 0 || x > game->x - 1)
		return (0);
	if (y < 0 || y > game->y - 1)
		return (0);
	if (game->map[y][x] != '1')
		return (1);
	return (0);
}

void	flood_fill(t_data *game, int x, int y)//Si != 1, check chemins en remplacants pas des X.
{
	if (valid_cross(game, x, y))
	{
		if (game->check_path[y][x] == 'X')
			return;
		if ((game->check_path[y][x] == 'E') || (game->check_path[y][x] == 'C'))
			game->check_path[y][x] = '0';
		game->check_path[y][x] = 'X';
		flood_fill(game, x - 1, y);
		flood_fill(game, x + 1, y);
		flood_fill(game, x, y - 1);
		flood_fill(game, x, y + 1);
	}
	return ;
}

void	verif_path(t_data *game)
{
	int	x;
	int	y;

	flood_fill(game, game->copy_player_x, game->copy_player_y);
	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (((game->map[y][x] == 'C') || (game->map[y][x] == 'E'))
				&& (game->check_path[y][x] != 'X'))
			{
				ft_free_error("ERROR\nPath is not valid!\n", game);
			}
			x++;
		}
		y++;
	}
}

void	init_game(t_data *game)
{
	check_pos(game);
	verif_path(game);
	game->img_pxl = 64;
	game->moves = 0;
	game->collect_points = 0;
	game->total_collect_points = count_items(game, 'C');
	game->mlx = mlx_init();
    if (game->y > 21)
        ft_error("ERROR\nThe size of the map is too large!\n");
    if (game->x > 40)
        ft_error("ERROR\nThe size of the map is too long!\n");
	game->mlx_win = mlx_new_window(game->mlx, game->img_pxl * game->x, game->img_pxl * game->y, "so_long");
	get_image_adr(game);
	display_image(game->mlx, game->mlx_win, game, game->map);
	mlx_hook(game->mlx_win, 17, 0, &red_cross, game);//17 = hooking event: ON_DESTROY
	mlx_hook(game->mlx_win, 2, 0, &key_press, game);//2 = hooking event: ON_KEYDOWN
	mlx_loop(game->mlx);
}
