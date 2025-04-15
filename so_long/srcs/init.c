/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:14:38 by williamguer       #+#    #+#             */
/*   Updated: 2025/04/15 18:02:28 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_struct_map(t_data *data, char **av)
		// Initialisation des valeurs de la structure map
{
	data->map.collectibles = 0;
	data->map.exit = 0;
	data->map.map = NULL;
	data->map.mapname = av[1];
	data->map.wall = 0;
	data->map.space = 0;
	data->map.player = 0;
	data->map.player_x = 0;
	data->map.player_y = 0;
	data->map.exit_x = 0;
	data->map.exit_y = 0;
}

void	init_struct_data2(t_data *data) // Initialisation des valeurs et images de la structure img et mlx via data
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
		exitmlx(data, "Error\nFailed to load images\n");
}

void	init_struct_data(t_data *data)
{
	data->mlx.height = 64;
	data->mlx.width = 64;
	data->img.floor = "ASSETS/floor.xpm";
	data->img.wall = "ASSETS/wall.xpm";
	data->img.player = "ASSETS/player.xpm";
	data->img.exitclose = "ASSETS/exitclose.xpm";
	data->img.exitopen = "ASSETS/exitopen.xpm";
	data->img.collectible = "ASSETS/collectible.xpm";
	init_struct_data2(data);
}

void	exitmlx(t_data *data, char *err)
{
	if (data->mlx.imgfloor)
		mlx_destroy_image(data->mlx.ptr, data->mlx.imgfloor);
	else if (data->mlx.imgwall)
		mlx_destroy_image(data->mlx.ptr, data->mlx.imgwall);
	else if (data->mlx.imgplayer)
		mlx_destroy_image(data->mlx.ptr, data->mlx.imgplayer);
	else if (data->img.exitclose)
		mlx_destroy_image(data->mlx.ptr, data->mlx.imgexitclose);
	else if (data->mlx.imgexitopen)
		mlx_destroy_image(data->mlx.ptr, data->mlx.imgexitopen);
	else if (data->mlx.imgcollectible)
		mlx_destroy_image(data->mlx.ptr, data->mlx.imgcollectible);
	mlx_destroy_display(data->mlx.ptr);
	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	free_and_exit(data, err);
}
void	my_mlx_put_image_to_window(t_data data, int i, int j, void *img)
{
	if (!img)
		exitmlx(&data, "Error\n Failed to put image to window\n");
	mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, img, (data.mlx.height
			* j), (data.mlx.width * i));
}

int	rendering(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == '1')
				my_mlx_put_image_to_window(*data, i, j, data->mlx.imgwall);
			else if (data->map.map[i][j] == 'C')
				my_mlx_put_image_to_window(*data, i, j,
					data->mlx.imgcollectible);
			else if (data->map.map[i][j] == '0')
				my_mlx_put_image_to_window(*data, i, j, data->mlx.imgfloor);
			else if (data->map.map[i][j] == 'P')
				my_mlx_put_image_to_window(*data, i, j, data->mlx.imgplayer);
			else if (data->map.map[i][j] == 'E')
				my_mlx_put_image_to_window(*data, i, j, data->mlx.imgexitclose);
			j++;
		}
		i++;
	}
	return (0);
}

void	set_mlx(t_data *data)
{
	data->mlx.win = mlx_new_window(data->mlx.ptr, 3840, 2160, "so_long");
	if (!data->mlx.win)
		free_and_exit(data, "Error\nFailed to create window\n");
	rendering(data);
	mlx_hook(data->mlx.ptr, KeyPress, KeyPressMask, keyhandler, data); //////////////////////////////
	mlx_loop(data->mlx.ptr);
}
