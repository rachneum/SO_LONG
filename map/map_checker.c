/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:48:28 by rachou            #+#    #+#             */
/*   Updated: 2024/07/09 14:43:05 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_is_rectangular(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (ft_strlen(map[y]) != ft_strlen(map[0]))
			return (0);
		y++;
	}
	return (1);
}

int	map_is_closed(char **map)//à corriger.
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		if (map[0][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (map[y])
	{
		if (map[y][0] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	item_is_valid(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != '\n')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	count_items(char **map, char item)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == item)
				count++;
			x++;
		}
		y++;	
	}
	return (count);
}

void	map_is_valid(char **map)
{
	if (!map_is_rectangular(map))
		ft_free_error("Error\nMap is not rectangular!\n", map);
	else if (!map_is_closed(map))
		ft_free_error("Error\nMap is not closed!\n", map);
	else if (!item_is_valid(map))
		ft_free_error("Error\nMap contains invalid items!\n", map);
	else if (count_items(map, 'C') < 1)//"C": collectables.
		ft_free_error("Error\nMap does not have at least one item!\n", map);
	else if (count_items(map, 'E') < 1)//"E": exit.
		ft_free_error("Error\nMap does not have at least one exit!\n", map);
	else if (count_items(map, 'P') != 1)//"P": player's starting position.
		ft_free_error("Error\nMap player's starting position is invalid!\n", map);
}
