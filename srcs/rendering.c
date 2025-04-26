/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:32:18 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/24 00:50:29 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_put_image_to_window(t_data data, int i, int j, void *img)
{
	if (!img)
		exitmlx(&data, "Error\n Failed to put image to window", true);
	mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, img,
		(data.mlx.height * j), (data.mlx.width * i));
}

void	load_images(t_data *data, int i, int j)
{
	if (data->map.map[i][j] == '1')
		my_mlx_put_image_to_window(*data, i, j, data->mlx.imgwall);
	else if (data->map.map[i][j] == 'C')
		my_mlx_put_image_to_window(*data, i, j, data->mlx.imgcollectible);
	else if (data->map.map[i][j] == '0')
		my_mlx_put_image_to_window(*data, i, j, data->mlx.imgfloor);
	else if (data->map.map[i][j] == 'P')
		my_mlx_put_image_to_window(*data, i, j, data->mlx.imgplayer);
	else if (data->map.map[i][j] == 'E')
	{
		my_mlx_put_image_to_window(*data, i, j, data->mlx.imgexitclose);
		if (data->map.collectibles == 0)
			my_mlx_put_image_to_window(*data, i, j, data->mlx.imgexitopen);
	}
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
			load_images(data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
