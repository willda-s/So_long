/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:18:31 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/23 21:15:04 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_mlx(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		free_and_exit(data, "Error\n Init fail");
	init_struct_data(data);
	set_mlx(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		tmp;
	char	**dst;

	if (ac == 2 && check_mapname(av[1]))
	{
		init_struct_map(&data, av);
		get_map(&data);
		pars_wall(&data);
		get_data(&data);
		dst = map_double(&data);
		tmp = data.map.collectibles;
		floodfill(dst, data.map.player_x, data.map.player_y, &data);
		free_tab(dst);
		if (data.map.collectibles != 0 || data.map.exit > 0)
			free_and_exit(&data, "Error\nMap impossible");
		data.map.collectibles = tmp;
		main_mlx(&data);
	}
	else
		ft_putstr_fd("Error\nArguments is not valid", 2);
	return (0);
}
