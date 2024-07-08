/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:33:52 by rachou            #+#    #+#             */
/*   Updated: 2024/07/08 14:47:08 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;
	
	fd = open(file, O_RDONLY, 0777);//Faut-il donner les doits au cas où ou pas??
	if (fd == -1)
		ft_error("ERROR\nMap file opening has failed!\n");
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		count++;
		free(line);
	}
	return (count);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_error(char *str, char **map)
{
	ft_free_map(map);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
