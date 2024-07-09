/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:06:21 by rachou            #+#    #+#             */
/*   Updated: 2024/07/09 14:36:00 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Créer fenêtre + afficher img.

void	init_win(void)
{
    void	*mlx;
	void	*mlx_win;


    mlx = mlx_init();//Initialise la connexion à la MiniLibX.
	if (!mlx)
		ft_error("ERROR\nThe connection with the MiniLibX has failed!\n");
	mlx_win = mlx_new_window(mlx, 600, 600, "");
	if (!mlx_win)
		ft_error("ERROR\nThe creation of a new window has failed!\n");
	mlx_loop(mlx);
	return ;
}
