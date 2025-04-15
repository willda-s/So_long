/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:39:25 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/15 18:03:32 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int keyhandler(t_data *data, int keycode)
{
	if (keycode == XK_W || keycode == XK_Up)
	{
		printf("OK\n");
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	}
	return (0);
}
