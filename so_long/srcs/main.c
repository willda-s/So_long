/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:18:31 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/09 21:45:02 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void init_struct_map(t_map *map, char **av)
{
	map->collectibles = 0;
	map->exit = 0;
	map->map = NULL;
	map->mapname = av[1];
	map->wall = 0;
	map->space = 0;
	map->player = 0;
	map->player_x = 0;
	map->player_y = 0;
}

// void print_struct_map(t_map map)
// {
// 	ft_printf("collectibles: %d\n", map.collectibles);
// 	ft_printf("exit: %d\n", map.exit);
// 	ft_printf("wall: %d\n", map.wall);
// 	ft_printf("space: %d\n", map.space);
// 	ft_printf("player: %d\n", map.player);
// }

int main2(t_data *data)
{
	data->mlx.mlx = mlx_init();
	init_struct_data(data);
	set_mlx(data);
	
}
int main(int ac, char **av)
{
	t_map map;
	t_data data;

	if (ac == 2 && check_mapname(av[1]))
	{
		init_struct_map(&map, av);
		get_map(&map);
		pars_wall(map);
		get_data(&map);
		floodfill(&map, map.player_x, map.player_y);
		if (map.collectibles > 0)
		{
			free_map(&map);
			ft_printf("Error\nNot all collectibles are reachable\n");
			exit(EXIT_FAILURE);
		}
		main2(&map);
		free_map(&map);
	} 
	else
		return(printf("Error\nArguments is not valid\n"));
}

