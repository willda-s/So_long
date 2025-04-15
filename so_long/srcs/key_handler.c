/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:39:25 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/15 23:21:46 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int keyhandler(t_data *data, int keycode)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
		exit(0);
	}
	else if (keycode == XK_Up || keycode == XK_w)
		move_up(data);
	else if (keycode == XK_Down || keycode == XK_s)
		move_down(data);
	else if (keycode == XK_Left || keycode == XK_a)
		move_left(data);
	else if (keycode == XK_Right || keycode == XK_d)
		move_right(data);
	else
		ft_printf("Error\n Invalid key\n");
	check_exit(data);	
	return (0);
}

void move_up(t_data *data)
{
	if (data->map.map[data->map.player_x - 1][data->map.player_y] != '1')
	{
		if (data->map.map[data->map.player_x - 1][data->map.player_y] == 'C')
			data->map.collectibles--;
		data->map.map[data->map.player_x][data->map.player_y] = '0';
		data->map.player_x--;
		data->map.map[data->map.player_x][data->map.player_y] = 'P';
	}
}
void move_down(t_data *data)
{
	if (data->map.map[data->map.player_x + 1][data->map.player_y] != '1')
	{
		if (data->map.map[data->map.player_x + 1][data->map.player_y] == 'C')
			data->map.collectibles--;
		data->map.map[data->map.player_x][data->map.player_y] = '0';
		data->map.player_x++;
		data->map.map[data->map.player_x][data->map.player_y] = 'P';
	}
}
void move_left(t_data *data)
{
	if (data->map.map[data->map.player_x][data->map.player_y - 1] != '1')
	{
		if (data->map.map[data->map.player_x][data->map.player_y - 1] == 'C')
			data->map.collectibles--;
		data->map.map[data->map.player_x][data->map.player_y] = '0';
		data->map.player_y--;
		data->map.map[data->map.player_x][data->map.player_y] = 'P';
	}
}
void move_right(t_data *data)
{
	if (data->map.map[data->map.player_x][data->map.player_y + 1] != '1')
	{
		if (data->map.map[data->map.player_x][data->map.player_y + 1] == 'C')
			data->map.collectibles--;
		data->map.map[data->map.player_x][data->map.player_y] = '0';
		data->map.player_y++;
		data->map.map[data->map.player_x][data->map.player_y] = 'P';
	}
}
void check_exit(t_data *data)
{
	if (data->map.collectibles == 0)
	{
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
		exit(0);
	}
}