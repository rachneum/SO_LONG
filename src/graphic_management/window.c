/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:06:21 by rachou            #+#    #+#             */
/*   Updated: 2024/06/05 15:39:39 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_win(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  *img;

    mlx = mlx_init();//initialise la connexion à la MiniLibX.
    if (!mlx)
        return ;
    mlx_win = mlx_new_window(mlx, 600, 600, "Hello world!");//mlx_new_window: Crée une nouvelle fenêtre de 600x600 pixels avec le titre "Hello world!". mlx_win: stocke le pointeur vers cette nouvelle fenêtre.
    img = malloc(sizeof(t_data));
    if (!img)
        return ;
    img->img = mlx_new_image(mlx, 600, 600);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
    mlx_loop(mlx);
    free(img);
    return ;
}
 