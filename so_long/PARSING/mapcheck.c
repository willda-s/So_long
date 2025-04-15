/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:53:42 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/10 23:12:32 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int count_line(t_data data) //compte le nombre de lignes dans le fichier
{
	int i;
	char *line;
	int fd;

	i = 0;
	line = NULL;
	fd = open(data.map.mapname, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n, Open fail");
		exit(errno);
	}
	while((line = get_next_line(fd)))
	{
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

bool check_mapname(char *av) //verifie le nom du fichier
{
	int len;

	len = ft_strlen(av) - 1;
	if ((av[0] != '.') && ((av[len] == 'r') && (av[len - 1] == 'e') 
					&& (av[len - 2] == 'b') && (av[len - 3] == '.')))
		return(true);
	else
		return(false);
}

void check_length(t_data *data) //verifie la longueur de chaque ligne
{
	int i;
	size_t len;
	int lastline;

	i = 1;
	if (!data->map.map[0])
		return;
	len = ft_strlen(data->map.map[0]);
	lastline = count_line(*data) - 1;
	while(i <= lastline)
	{
		if (len != ft_strlen(data->map.map[i]))
			free_and_exit(data, "Error\n line not same length\n");
		i++;
	}
}

void get_map(t_data *data) //recupere la map a partir du .ber et la stocke dans un char ** et verifie la longueur des lignes
{
	int i;
	char *line;
	int len;
	int fd;

	i = 0;
	fd = open(data->map.mapname, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n Open fail");
		exit(errno);
	}
	len = count_line(*data);
	if (len < 3)
	{
		close(fd);
		ft_printf("Error\n Map incorrect");
		exit(EXIT_FAILURE);
	}
	data->map.map = ft_calloc(len + 1, sizeof(char *));
	if (!data->map.map)
	{
		close(fd);
		ft_printf("Error\n Malloc fail");
		exit(EXIT_FAILURE);
	}
	while((line = get_next_line(fd)))
	{
		data->map.map[i] = ft_strtrim(line, "\n");
		if (!data->map.map[i])
		{
			free(line);
			free_and_exit(data, "Error\n Malloc fail strtrim");
		}	
		free(line);
		i++;
	}
	free(line);
	close(fd);
	check_length(data);
}
