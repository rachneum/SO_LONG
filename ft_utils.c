/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:56:22 by rachou            #+#    #+#             */
/*   Updated: 2024/07/09 14:30:57 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *str, int fd)
{
    int	i;

    if (!str || (fd == -1))// ou !fd?
        return ;
    i = 0;
    while (str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
}

int	ft_strlen(char *str)
{
    int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
