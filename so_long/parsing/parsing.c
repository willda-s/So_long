/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:27:35 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/23 19:35:42 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->map.player_x = j;
				data->map.player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	get_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'C')
				data->map.collectibles++;
			else if (data->map.map[i][j] == 'E')
				data->map.exit++;
			else if (data->map.map[i][j] == 'P')
				data->map.player++;
			j++;
		}
		i++;
	}
	check_double(data);
	get_player_pos(data);
}
