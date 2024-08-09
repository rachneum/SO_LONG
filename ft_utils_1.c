/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:05:12 by rachou            #+#    #+#             */
/*   Updated: 2024/08/09 14:44:52 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, void *src, int n)
{
	int		i;
	char	*dest;
	char	*source;

	i = 0;
	dest = dst;
	source = (char *)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *s1)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, size);
	dest[size] = '\0';
	return (dest);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (!str || (fd == -1))
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
