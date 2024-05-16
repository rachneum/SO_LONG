/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:56:22 by rachou            #+#    #+#             */
/*   Updated: 2024/05/16 16:49:17 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen(char *str)
{
    int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void ft_putstr_fd(char *str, int fd)
{
	int	len;

	if (!str || !fd)
		return ;
	len = ft_strlen(str);
	write(fd, &str, len);
}

void	error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	free_error(char *str)
{
	free_map(map);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
