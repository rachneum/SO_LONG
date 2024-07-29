/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:08:22 by rachou            #+#    #+#             */
/*   Updated: 2024/07/29 16:29:07 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_is_rectangular(t_data *game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		if (ft_strlen(game->map[y]) != ft_strlen(game->map[0]))
			return (0);
		y++;
	}
	return (1);
}

/*int	map_is_closed(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1')
			return (0);
		x++;
	}
	y = -1;
	//x--;
	while (game->map[++y][x])
		if (game->map[y][x] != '1')
			return (0);
	y = 0;
	while (game->map[y])
	{
		if (game->map[y][0] != '1')
			return (0);
		y++;
	}
	x = -1;
	//y--;
	while (game->map[y][++x])
		if (game->map[y][x] != '1')
			return (0);
	return (1);
}*/

int	item_is_valid(t_data *game)
{
	(void) game;
	//int	x;
	//int	y;
//
	//y = 0;
	//while (game->map[y])
	//{
	//	x = 0;
	//	while (game->map[y][x])
	//	{
	//		if (game->map[y][x] != '0' && game->map[y][x] != '1' && game->map[y][x] != 'C'
	//			&& game->map[y][x] != 'E' && game->map[y][x] != 'P' && game->map[y][x] != '\n')
	//			return (0);
	//		x++;
	//	}
	//	y++;
	//}
	return (1);
}

int	count_items(t_data *game, char item)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == item)
				count++;
			x++;
		}
		y++;	
	}
	return (count);
}

void	map_is_valid(t_data *game)
{
	if (!map_is_rectangular(game))
		ft_free_error("Error\nMap is not rectangular!\n", game);
	/*else if (!map_is_closed(game))
		ft_free_error("Error\nMap is not closed!\n", game);*/
	else if (!item_is_valid(game))
		ft_free_error("Error\nMap contains invalid items!\n", game);
	else if (count_items(game, 'C') < 1)
		ft_free_error("Error\nMap does not have at least one item!\n", game);
	else if (count_items(game, 'E') < 1)
		ft_free_error("Error\nMap does not have at least one exit!\n", game);
	else if (count_items(game, 'P') != 1)
		ft_free_error("Error\nMap player's starting position is invalid!\n", game);
}
