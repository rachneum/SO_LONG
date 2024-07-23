/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:52:45 by rachou            #+#    #+#             */
/*   Updated: 2024/07/23 11:28:44 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int count_length(char *file)
{
	int		fd;
	char	*line;
	
	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		ft_error("ERROR\nMap file opening has failed!\n");
	line = get_next_line(fd);
	return (ft_strlen(line));
}

int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;
	
	fd = open(file, O_RDONLY, 0777);
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

void	ft_free_map(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i] != NULL)
		i++;
	}
}

void	ft_free_error(char *str, t_data *game)
{
	ft_free_map(game);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
