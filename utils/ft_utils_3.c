/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:29:50 by rachou            #+#    #+#             */
/*   Updated: 2024/08/09 15:02:20 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_free_map(t_data *game)
{
	int	y;

	y = 0;
	if (game->map != NULL)
	{
		while (game->map[y] != NULL)
		{
			free(game->map[y]);
			y++;
		}
		free(game->map);
		game->map = NULL;
	}
}

void	ft_free_error(char *str, t_data *game)
{
	ft_free_map(game);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_free_check_path(t_data *game)
{
	int	y;

	y = 0;
	if (game->check_path != NULL)
	{
		while (game->check_path[y] != NULL)
		{
			free(game->check_path[y]);
			y++;
		}
		free(game->check_path);
		game->check_path = NULL;
	}
	exit(EXIT_FAILURE);
}
