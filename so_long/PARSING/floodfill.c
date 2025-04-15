/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:53:01 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/10 22:59:27 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void free_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char **map_double(t_data data)
{
	char **dst;
	int i;
	int len;

	i = 0;
	len = count_line(data);
	dst = malloc(sizeof(char *) * (len + 1));
	while(i < len)
	{
		dst[i] = ft_strdup(data.map.map[i]);
		if (!dst[i])
		{
			free_tab(dst);
			free_and_exit(&data, "Error\n Malloc fail");
		}
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

void floodfill(char **dst, int player_x, int player_y, t_data *data) //remplace les '0' par '1' pour verifier si le joueur peut acceder a tous les 'C'
{
	if (player_x < 0 || player_y < 0 || player_x >= count_line(*data) || !data->map.map[player_x] || (size_t)player_y >= ft_strlen(data->map.map[0]))
		return; 
	if (dst[player_x][player_y] == '1' || dst[player_x][player_y] == 'V')
		return;
	if (dst[player_x][player_y] == 'E')
	{
		data->map.exit--;
		return;
	}
	if (dst[player_x][player_y] == 'C')
		data->map.collectibles--;
	dst[player_x][player_y] = 'V';
	if (data->map.collectibles == 0 && data->map.exit == 0)
		return;
	floodfill(dst, player_x - 1, player_y, data);
	floodfill(dst, player_x + 1, player_y, data);
	floodfill(dst, player_x, player_y - 1, data);
	floodfill(dst, player_x, player_y + 1, data);
}
