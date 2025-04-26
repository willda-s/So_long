/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:14:38 by williamguer       #+#    #+#             */
/*   Updated: 2025/04/24 00:22:18 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_map(t_data *data, char **av)
{
	ft_bzero(&data->map, sizeof(t_data));
	data->map.mapname = av[1];
}

void	init_struct_data2(t_data *data)
{
	data->mlx.imgfloor = mlx_xpm_file_to_image(data->mlx.ptr, data->img.floor,
			&data->mlx.width, &data->mlx.height);
	data->mlx.imgwall = mlx_xpm_file_to_image(data->mlx.ptr, data->img.wall,
			&data->mlx.width, &data->mlx.height);
	data->mlx.imgplayer = mlx_xpm_file_to_image(data->mlx.ptr, data->img.player,
			&data->mlx.width, &data->mlx.height);
	data->mlx.imgexitclose = mlx_xpm_file_to_image(data->mlx.ptr,
			data->img.exitclose, &data->mlx.width, &data->mlx.height);
	data->mlx.imgexitopen = mlx_xpm_file_to_image(data->mlx.ptr,
			data->img.exitopen, &data->mlx.width, &data->mlx.height);
	data->mlx.imgcollectible = mlx_xpm_file_to_image(data->mlx.ptr,
			data->img.collectible, &data->mlx.width, &data->mlx.height);
	if (!data->mlx.imgfloor || !data->mlx.imgwall || !data->mlx.imgplayer
		|| !data->mlx.imgexitclose || !data->mlx.imgexitopen
		|| !data->mlx.imgcollectible)
		exitmlx(data, "Error\nFailed to load images", false);
}

void	init_struct_data(t_data *data)
{
	data->mlx.height = 64;
	data->mlx.width = 64;
	if (data->mlx.height * data->map.width > 2160 || data->mlx.width
		* data->map.length > 3840)
	{
		mlx_destroy_display(data->mlx.ptr);
		free(data->mlx.ptr);
		free_and_exit(data, "Error\n map too big");
	}
	data->img.floor = "assets/floor.xpm";
	data->img.wall = "assets/wall.xpm";
	data->img.player = "assets/player.xpm";
	data->img.exitclose = "assets/exitclose.xpm";
	data->img.exitopen = "assets/exitopen.xpm";
	data->img.collectible = "assets/collectible.xpm";
	init_struct_data2(data);
}

int	close_window(t_data *data)
{
	exitmlx(data, "", true);
	return (1);
}

void	set_mlx(t_data *data)
{
	data->mlx.win = mlx_new_window(data->mlx.ptr, data->mlx.width
			* data->map.length, data->mlx.height * data->map.width,
			"so_long");
	if (!data->mlx.win)
		exitmlx(data, "Error\n Create new window fail", false);
	mlx_expose_hook(data->mlx.win, rendering, data);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask, &keyhandler, data);
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask, close_window,
		data);
	mlx_loop(data->mlx.ptr);
}
