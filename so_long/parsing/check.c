/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:35:51 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/23 20:06:00 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_double(t_data *data)
{
	if (data->map.exit != 1)
		free_and_exit(data, "Error\n More or less than one exit");
	else if (data->map.player != 1)
		free_and_exit(data, "Error\n More or less than one player");
	else if (data->map.collectibles < 1)
		free_and_exit(data, "Error\n No collectibles");
}

bool	check_mapname(char *av)
{
	int	len;

	len = ft_strlen(av) - 1;
	if ((av[len] == 'r') && (av[len - 1] == 'e') && (av[len - 2] == 'b')
		&& (av[len - 3] == '.') && (av[len - 4] != '/'))
		return (true);
	else
		return (false);
}

void	check_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] != '1' && data->map.map[i][j] != '0'
				&& data->map.map[i][j] != 'C' && data->map.map[i][j] != 'P'
				&& data->map.map[i][j] != 'E')
				free_and_exit(data, "Error\n Char incorrect");
			j++;
		}
		i++;
	}
}

void	check_length(t_data *data)
{
	size_t	i;

	i = 1;
	if (!data->map.map || !data->map.map[0])
		return ;
	data->map.length = ft_strlen(data->map.map[0]);
	while (data->map.map[i])
	{
		if (data->map.length != ft_strlen(data->map.map[i]))
			free_and_exit(data, "Error\n line not same length");
		i++;
	}
	check_char(data);
}
