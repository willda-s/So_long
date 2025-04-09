/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:14:38 by williamguer       #+#    #+#             */
/*   Updated: 2025/04/09 21:53:32 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_struct_data(t_data *data)
{
    data->mlx.height = 80;
    data->mlx.width = 80;
    data->img.floor = "imgs/floor.xpm";
    data->img.wall = "imgs/wall.xpm";
    data->img.player = "imgs/player.xpm";
    data->img.exit = "imgs/exit.xpm";
    data->img.collectible = "imgs/collectible.xpm";
    data->mlx.imgfloor = mlx_xpm_file_to_image(data->mlx.mlx, data->img.floor, &data->mlx.width, &data->mlx.height);
    data->mlx.imgwall = mlx_xpm_file_to_image(data->mlx.mlx, data->img.wall, &data->mlx.width, &data->mlx.height);
    data->mlx.imgplayer = mlx_xpm_file_to_image(data->mlx.mlx, data->img.player, &data->mlx.width, &data->mlx.height);
    data->mlx.imgexit = mlx_xpm_file_to_image(data->mlx.mlx, data->img.exit, &data->mlx.width, &data->mlx.height);
    data->mlx.imgcollectible = mlx_xpm_file_to_image(data->mlx.mlx, data->img.collectible, &data->mlx.width, &data->mlx.height);
    if (!data->mlx.imgfloor || !data->mlx.imgwall || !data->mlx.imgplayer || !data->mlx.imgexit || !data->mlx.imgcollectible)
    {
        ft_printf("Error\nFailed to load images\n");
        exit(1);
    }
}

void set_mlx (t_data *data)
{
    data->mlx.win = mlx_new_window(data->mlx.mlx, 800, 600, "so_long");
    if (!data->mlx.win)
    {
        ft_printf("Error\nFailed to create window\n");
        exit(1);
    }
    
}

