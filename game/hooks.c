/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:43:51 by rachou            #+#    #+#             */
/*   Updated: 2024/07/14 18:06:25 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	return (0);
}
