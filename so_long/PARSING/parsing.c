/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:27:35 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/11 00:43:09 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_double(t_data data) //verifie s'il y a bien une sortie, un joueur, et au moins un collectible
{
	if (data.map.exit != 1)
		free_and_exit(&data, "Error\n More or less than one exit\n");
	else if (data.map.player != 1)
		free_and_exit(&data, "Error\n More or less than one player\n");
	else if (data.map.collectibles < 1)
		free_and_exit(&data, "Error\n No collectibles\n");
}

void get_player_pos(t_data *data)//recupere la position du joueur dans la map
{
	int i;
	int j;

	i = 0;
	while(data->map.map[i])
	{
		j = 0;
		while(data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->map.player_x = i;
				data->map.player_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void get_exit_pos(t_data *data)//recupere la position de la sortie dans la map
{
	int i;
	int j;

	i = 0;
	while(data->map.map[i])
	{
		j = 0;
		while(data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'E')
			{
				data->map.exit_x = i;
				data->map.exit_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
void get_data(t_data *data)//compte le nombre d'element dans la map
{
	int i;
	int j;

	i = 0;
	while(data->map.map[i])
	{
		j = 0;
		while(data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'C')
				data->map.collectibles++;
			else if (data->map.map[i][j] == 'E')
				data->map.exit++;
			else if (data->map.map[i][j] == '1')
				data->map.wall++;
			else if (data->map.map[i][j] == '0')
				data->map.space++;
			else if (data->map.map[i][j] == 'P')
				data->map.player++;
			j++;
		}
		i++;
	}
	check_double(*data);
	get_player_pos(data);
}
