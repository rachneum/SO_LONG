/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:24:15 by rachou            #+#    #+#             */
/*   Updated: 2024/07/08 14:48:32 by rachou           ###   ########.fr       */
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
