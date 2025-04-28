/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:25:12 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/26 16:58:56 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->map.width)
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
}

void	free_and_exit(t_data *data, char *err)
{
	if (!data->map.map || !data->map.map[0])
		free(data->map.map);
	else
		free_map(data);
	ft_putstr_fd(err, 2);
	exit(EXIT_SUCCESS);
}

void	exitmlx(t_data *data, char *err, bool destroy)
{
	if (data->mlx.imgfloor)
		mlx_destroy_image(data->mlx.ptr, data->mlx.imgfloor);
	if (data->mlx.imgwall)
		mlx_destroy_image(data->mlx.ptr, data->mlx.imgwall);
	if (data->mlx.imgplayer)
		mlx_destroy_image(data->mlx.ptr, data->mlx.imgplayer);
	if (data->mlx.imgexitclose)
		mlx_destroy_image(data->mlx.ptr, data->mlx.imgexitclose);
	if (data->mlx.imgexitopen)
		mlx_destroy_image(data->mlx.ptr, data->mlx.imgexitopen);
	if (data->mlx.imgcollectible)
		mlx_destroy_image(data->mlx.ptr, data->mlx.imgcollectible);
	if (destroy)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	if (data->mlx.ptr)
	{
		mlx_destroy_display(data->mlx.ptr);
		free(data->mlx.ptr);
	}
	free_and_exit(data, err);
}
