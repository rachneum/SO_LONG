/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:52:45 by rachou            #+#    #+#             */
/*   Updated: 2024/08/09 15:02:36 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_length(char *file, t_data *game)
{
	int		fd;
	int		leng;
	char	*line;

	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		ft_free_error("ERROR\nMap file opening has failed!\n", game);
	line = get_next_line(fd);
	leng = ft_strlen(line);
	free(line);
	return (leng);
}

int	count_lines(char *file, t_data *game)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		ft_free_error("ERROR\nMap file opening has failed!\n", game);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	return (count);
}
