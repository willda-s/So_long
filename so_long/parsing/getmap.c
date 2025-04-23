/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:53:42 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/23 21:51:43 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*gnl_with_secure(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (errno == 1)
	{
		close(fd);
		free_and_exit(data, "Error\nGNL fail");
	}
	return (line);
}

void	strtrim_with_secure(t_data *data, char *line, int fd, int i)
{
	data->map.map[i] = ft_strtrim(line, "\n");
	if (!data->map.map || !data->map.map[i])
	{
		free(line);
		close(fd);
		free_and_exit(data, "Error\n Malloc fail strtrim");
	}
}

int	count_line(t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(data->map.mapname, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nOpen fail", 2);
		exit(errno);
	}
	line = gnl_with_secure(data, fd);
	while (line)
	{
		i++;
		free(line);
		line = gnl_with_secure(data, fd);
	}
	free(line);
	close(fd);
	return (i);
}

static	int	get_map_part(t_data *data)
{
	int	fd;

	data->map.width = count_line(data);
	if (data->map.width < 3)
	{
		ft_putstr_fd("Error\n Map incorrect", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(data->map.mapname, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n Open fail", 2);
		exit(errno);
	}
	data->map.map = ft_calloc(data->map.width + 1, sizeof(char *));
	if (!data->map.map)
	{
		close(fd);
		ft_putstr_fd("Error\n Malloc fail", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	get_map(t_data *data)
{
	size_t	i;
	char	*line;
	int		fd;

	i = 0;
	fd = get_map_part(data);
	line = gnl_with_secure(data, fd);
	if (!line)
	{
		close(fd);
		free_and_exit(data, "Error\n, GNL fail");
	}
	while (line && i < data->map.width)
	{
		strtrim_with_secure(data, line, fd, i);
		free(line);
		i++;
		line = gnl_with_secure(data, fd);
	}
	free(line);
	close(fd);
	check_length(data);
}
