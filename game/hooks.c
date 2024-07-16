/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:43:51 by rachou            #+#    #+#             */
/*   Updated: 2024/07/16 12:40:22 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*void	move_player(t_data *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return ;
	game->moves++;
	ft_printf("nbr moves : %d\n", game->moves);
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->collect_points++;
		
	}


}*/

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
	/*if (keycode == KEY_UP || keycode == KEY_W)
		move_player(game, game->player_x, game->player_y - 1);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		move_player(game, game->player_x, game->player_y + 1);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_player(game, game->player_x + 1, game->player_y);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		move_player(game, game->player_x - 1, game->player_y);*/
	return (0);
}
