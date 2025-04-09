/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:27:35 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/09 21:44:53 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
int count_line(t_map map) //compte le nombre de lignes dans le fichier
{
	int i;
	char *line;
	int fd;

	i = 0;
	line = NULL;
	fd = open(map.mapname, O_RDONLY);
	if (fd == -1)
	{
		perror("Erro\n, Open fail");
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

// void print_map(t_map map)
// {
// 	int i;
// 	int len;

// 	i = 0;
// 	len = count_line(map);
// 	while(i < len)
// 	{
// 		ft_printf("%s\n", map.map[i]);
// 		i++;
// 	}
// }

void free_map(t_map *map)
{
	int i;
	int len;

	i = 0;
	len = count_line(*map);
	while(i < len)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void check_length(t_map map) //verifie la longueur de chaque ligne
{
	int i;
	size_t len;
	int lastline;

	i = 1;
	len = ft_strlen(map.map[0]);
	lastline = count_line(map) - 1;
	while(i <= lastline)
	{
		if (len != ft_strlen(map.map[i]))
		{
			free_map(&map);
			ft_printf("Error\n Line %d not same length\n", i + 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void get_map(t_map *map) //recupere la map a partir du .ber et la stocke dans un char ** et verifie la longueur des lignes
{
	int i;
	char *line;
	int len;
	int fd;

	i = 0;
	fd = open(map->mapname, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n Open fail");
		exit(errno);
	}
	len = count_line(*map);
	map->map = malloc(sizeof(char *) * len + 1);
	if (!map->map)
	{
		ft_printf("Error\n Malloc fail");
		exit(EXIT_FAILURE);
	}
	while((line = get_next_line(fd)))
	{
		map->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	free(line);
	close(fd);
	check_length(*map);
}

void check_double(t_map map)
{
	if (map.exit > 1)
	{
		free_map(&map);
		ft_printf("Error\n More than one exit\n");
		exit(EXIT_FAILURE);
	}
	else if (map.exit < 1)
	{
		free_map(&map);
		ft_printf("Error\n No exit\n");
		exit(EXIT_FAILURE);
	}
	else if (map.player > 1)
	{
		free_map(&map);
		ft_printf("Error\n More than one player\n");
		exit(EXIT_FAILURE);
	}
	else if (map.player < 1)
	{
		free_map(&map);
		ft_printf("Error\n No player\n");
		exit(EXIT_FAILURE);
	}
	else if (map.collectibles < 1)
	{
		free_map(&map);
		ft_printf("Error\n No collectibles\n");
		exit(EXIT_FAILURE);
	}
}

void get_player_pos(t_map *map)
{
	int i;
	int j;

	i = 0;
	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->player_x = i;
				map->player_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void get_data(t_map *map)
{
	int i;
	int j;

	i = 0;
	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->collectibles++;
			else if (map->map[i][j] == 'E')
				map->exit++;
			else if (map->map[i][j] == '1')
				map->wall++;
			else if (map->map[i][j] == '0')
				map->space++;
			else if (map->map[i][j] == 'P')
				map->player++;
			j++;
		}
		i++;
	}
	check_double(*map);
	get_player_pos(map);
}


void floodfill(t_map *map, int player_x, int player_y) //remplace les '0' par '1' pour verifier si le joueur peut acceder a tous les 'C'
{
	if (player_x < 0 || player_y < 0 || player_x >= count_line(*map) || !map->map[player_x] || (size_t)player_y >= ft_strlen(map->map[0]))
		return;
	if (map->map[player_x][player_y] == '1' || map->map[player_x][player_y] == 'V')
		return;
	if (map->map[player_x][player_y] == 'E')
		map->exit--;
	if (map->map[player_x][player_y] == 'C')
		map->collectibles--;
	map->map[player_x][player_y] = 'V';
	if (map->collectibles == 0 && map->exit == 0)
	{
		ft_printf("All collectibles collected and exit reached!\n");
		return;
	}
	floodfill(map, player_x - 1, player_y);
	floodfill(map, player_x + 1, player_y);
	floodfill(map, player_x, player_y - 1);
	floodfill(map, player_x, player_y + 1);
}