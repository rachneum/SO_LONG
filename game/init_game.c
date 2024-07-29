/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:28:53 by rachou            #+#    #+#             */
/*   Updated: 2024/07/29 16:47:29 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*int	valid_cross(t_data *game, int x, int y)//M'assure de ne pas dépasser les limites de ma map.
{
	game->map[y][x] = 'P';
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
	printf("%d\n", valid_cross(game, x, y));
	//printf("salut\n");
	if (valid_cross(game, x, y))
	{
		printf("salut\n");
		if (game->check_path[x][y] == 'X')
			return;
		if (((game->check_path[x + 1][y] == 'E') || (game->check_path[x - 1][y] == 'E')
			|| ((game->check_path[x + 1][y] == 'C') || (game->check_path[x - 1][y] == 'C')))
			&& ((game->check_path[x][y + 1] == '1') || (game->check_path[x][y - 1] == '1')))
			return ;
		if (((game->check_path[x][y + 1] == 'E') || (game->check_path[x][y - 1] == 'E')
			|| ((game->check_path[1][y + 1] == 'C') || (game->check_path[x][y - 1] == 'C')))
			&& ((game->check_path[x + 1][y] == '1') || (game->check_path[x - 1][y] == '1')))
			return ;
		if ((game->check_path[x][y] == 'E') || (game->check_path[x][y] == 'C'))
			game->check_path[x][y] = '0';
		game->check_path[x][y] = 'X';
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

	flood_fill(game, game->player_x, game->player_y);
	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (((game->map[y][x] == 'C') || (game->map[y][x] == 'E'))
				&& (game->check_path[y][x] != 'X'))
			{
				ft_free_error_2("ERROR\n", game);
				ft_free_error("ERROR\n", game);
			}
			x++;
		}
		y++;
	}
}*/

void	init_game(t_data *game)
{
	//verif_path(game);
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
