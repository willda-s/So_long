/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:18:31 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/15 16:12:33 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


// void print_struct_map(t_data data)
// {
// 	ft_printf("collectibles: %d\n", data.map.collectibles);
// 	ft_printf("exit: %d\n", data.map.exit);
// 	ft_printf("wall: %d\n", data.map.wall);
// 	ft_printf("space: %d\n", data.map.space);
// 	ft_printf("player: %d\n", data.map.player);
// }

int main2(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		free_and_exit(data, "Error\n Init fail");
	init_struct_data(data);
	set_mlx(data);
	return(1);
}
int main(int ac, char **av)
{
	t_data data;
	char **dst;

	if (ac == 2 && check_mapname(av[1]))
	{
		init_struct_map(&data, av);
		get_map(&data);
		pars_wall(data);
		get_data(&data);
		dst = map_double(data);
		floodfill(dst, data.map.player_x, data.map.player_y, &data);
		free_tab(dst);
		if (data.map.collectibles > 0)
			free_and_exit(&data, "Error\nNot all collectibles are reachable\n");
		else 
			ft_printf("All collectibles collected and exit reached!\n");
		main2(&data);
		free_map(&data);
	} 
	else
		return(printf("Error\nArguments is not valid\n"));
}

