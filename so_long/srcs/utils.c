/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:25:12 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/15 18:05:52 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_map(t_data *data)
{
	int i;
	int len;

	i = 0;
	len = count_line(*data);
	while(i < len)
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
}

void print_map(t_data data)
{
	int i;
	int len;

	i = 0;
	len = count_line(data);
	while(i < len)
	{
		ft_printf("%s\n", data.map.map[i]);
		i++;
	}
}

void free_and_exit(t_data *data, char *err)
{
	// if (!data->map.map || !data->map.map[0])
	// {
	// 	free(data->map.map);
	// 	free(data->mlx.ptr);
	// 	ft_printf(err);
	// 	exit(EXIT_FAILURE);
	// }
	free_map(data);
	free(data->mlx.ptr);
	ft_printf(err);
	exit(EXIT_FAILURE);
}