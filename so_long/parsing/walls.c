/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:57:04 by williamguer       #+#    #+#             */
/*   Updated: 2025/04/23 20:28:19 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	first_last_wall(t_data *data)
{
	int	j;
	int	lenmax;

	j = 0;
	lenmax = count_line(data) - 1;
	while (data->map.map[0][j] != '\0')
	{
		if (data->map.map[0][j] != '1')
			free_and_exit(data, "Error\n First row not wall\n");
		j++;
	}
	j = 0;
	while (data->map.map[lenmax][j] != '\0')
	{
		if (data->map.map[lenmax][j] != '1')
			free_and_exit(data, "Error\n Last row not wall\n");
		j++;
	}
}

bool	pars_wall(t_data *data)
{
	int	i;
	int	len;
	int	linemax;

	i = 1;
	linemax = count_line(data) - 1;
	if (!data->map.map[0])
		return (false);
	len = ft_strlen(data->map.map[i]) - 1;
	first_last_wall(data);
	while (i <= linemax)
	{
		if (data->map.map[i][0] != '1' || data->map.map[i][len] != '1')
			free_and_exit(data, "Error\n Left or right not wall\n");
		i++;
	}
	return (true);
}
