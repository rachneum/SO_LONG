/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:43:51 by rachou            #+#    #+#             */
/*   Updated: 2024/07/24 13:26:45 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_data *game, int x, int y, int pos)
{
	if (game->map[y][x] == '1')
		return ;
	game->moves++;
	printf("number of moves : %d\n", game->moves);
	if (game->map[y][x] == '0' || game->map[y][x] == 'C' || game->map[y][x] == 'E')
	{
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collect_points++;
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
		//printf("%d\n", game->map[y][x]);
		put_floor(game, game->player_x, game->player_y);
		put_floor(game, x, y);
		put_character(game, x, y, pos);
		if (game->collect_points == game->total_collect_points)
		{
			put_exit(game, game->exit_x, game->exit_y);
			if (game->map[y][x] == 'E')
			{
				printf("YOU WON!\n");
				red_cross(game);
			}
		}
	}
}

int	ft_esc(int keycode, t_data *game)
{
	(void)keycode;
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	destroy_image(game);
	exit(0);
}


int	red_cross(t_data *data)
{
	ft_esc(0, data);
	return (1);
}

int	key_press(int keycode, t_data *game)
{
	if (keycode == KEY_ESCAPE)
		red_cross(game);
	if (keycode == KEY_UP || keycode == KEY_W)
		move_player(game, game->player_x, game->player_y - 1, 1);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		move_player(game, game->player_x, game->player_y + 1, 0);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_player(game, game->player_x + 1, game->player_y, 2);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		move_player(game, game->player_x - 1, game->player_y, 3);
	return (0);
}
