/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:06:21 by rachou            #+#    #+#             */
/*   Updated: 2024/06/07 14:15:05 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


void    init_win(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  *img;
    int     img_width;
    int     img_height;

    mlx = mlx_init(); // Initialise la connexion à la MiniLibX.
    mlx_win = mlx_new_window(mlx, 600, 600, "Hello world!"); // Crée une nouvelle fenêtre de 600x600 pixels avec le titre "Hello world!".
    img = malloc(sizeof(t_data));
    img->img = mlx_xpm_file_to_image(mlx, "./assets/bushes.xpm", &img_width, &img_height);
    //if (!img->img)
    //{
    //    fprintf(stderr, "Error: Failed to load image from file\n");
    //    free(img);
    //    return ;
    //}
    mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
    mlx_loop(mlx);
    mlx_destroy_image(mlx, img->img);
    free(img);
    return ;
}
