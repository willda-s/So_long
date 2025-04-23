/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:53:01 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/23 21:35:14 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**map_double(t_data *data)
{
	char	**dst;
	size_t	i;

	i = 0;
	dst = malloc(sizeof(char *) * (data->map.width + 1));
	if (!dst)
		free_and_exit(data, "Error\n dst malloc fail");
	while (i < data->map.width)
	{
		dst[i] = ft_strdup(data->map.map[i]);
		if (!dst[i])
		{
			free_tab(dst);
			free_and_exit(data, "Error\n Malloc fail");
		}
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

void	floodfill(char **dst, size_t player_x, size_t player_y, t_data *data)
{
	if (player_y < 0 || player_x < 0 || player_x >= data->map.length
		|| !data->map.map[player_y] || player_y >= data->map.width)
		return ;
	if (dst[player_y][player_x] == '1' || dst[player_y][player_x] == 'V')
		return ;
	if (dst[player_y][player_x] == 'E')
	{
		data->map.exit--;
		return ;
	}
	if (data->map.collectibles == 0 && data->map.exit == 0)
		return ;
	if (dst[player_y][player_x] == 'C')
		data->map.collectibles--;
	dst[player_y][player_x] = 'V';
	floodfill(dst, player_x, player_y - 1, data);
	floodfill(dst, player_x, player_y + 1, data);
	floodfill(dst, player_x - 1, player_y, data);
	floodfill(dst, player_x + 1, player_y, data);
}
