/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:39:25 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/23 19:21:18 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhandler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		exitmlx(data, "ESCAPE\n", true);
	else if (keycode == XK_Up || keycode == XK_w)
		move(data, -1, 0);
	else if (keycode == XK_Down || keycode == XK_s)
		move(data, 1, 0);
	else if (keycode == XK_Left || keycode == XK_a)
		move(data, 0, -1);
	else if (keycode == XK_Right || keycode == XK_d)
		move(data, 0, 1);
	return (0);
}

void	move(t_data *data, int incry, int incrx)
{
	char		nextpos;
	static int	mouvment = 0;

	nextpos = data->map.map[data->map.player_y + incry][data->map.player_x
		+ incrx];
	if (nextpos != '1')
	{
		if (nextpos == 'E')
		{
			if (data->map.collectibles == 0)
			{
				ft_printf("%d\n", ++mouvment);
				exitmlx(data, "GG\n", true);
			}
			else
				return ;
		}
		if (nextpos == 'C')
			data->map.collectibles--;
		data->map.map[data->map.player_y][data->map.player_x] = '0';
		data->map.player_y += incry;
		data->map.player_x += incrx;
		data->map.map[data->map.player_y][data->map.player_x] = 'P';
		ft_printf("%d\n", ++mouvment);
	}
}
