/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:57:04 by williamguer       #+#    #+#             */
/*   Updated: 2025/04/08 11:58:14 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void first_last_wall(t_map map)
{
	int j;
	int lenmax;
	
	j = 0;
	lenmax = count_line(map) - 1;
	while(map.map[0][j] != '\0')
	{
		if (map.map[0][j] != '1')
		{
			ft_printf("Error\n First row not wall\n");	
			exit(EXIT_FAILURE);
		}
		j++;
	}
	j = 0;
	while(map.map[lenmax][j] != '\0')
	{
		if (map.map[lenmax][j] != '1')
		{
			ft_printf("Error\n Last row not wall\n");	
			exit(EXIT_FAILURE);
		}
		j++;
	}
}
bool pars_wall(t_map map)
{
	int i;
	int len;
	int linemax;

	i = 1;
	linemax = count_line(map) - 1;
	len = ft_strlen(map.map[i]) - 1;
	first_last_wall(map);
	while(i <= linemax)
	{
		if (map.map[i][0] != '1' || map.map[i][len] != '1')
		{
			ft_printf("Error\n Left or right not wall\n");	
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return(true);
}