/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:22:05 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/09 21:42:05 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "fcntl.h"
#include "../GNL/get_next_line.h"
#include "math.h"
#include "errno.h"

typedef struct s_map 
{
	int collectibles;
	int exit;
	char **map;
	char *mapname;
	int wall;
	int space;
	int player;
	int player_x;
	int player_y;
}		t_map;

typedef struct s_mlx
{
	void *mlx;
	void *win;
	void *imgfloor;
	void *imgwall;
	void *imgplayer;
	void *imgexit;
	void *imgcollectible;
	int width;
	int height;
}				t_mlx;
typedef struct s_img
{
	char *floor;
	char *wall;
	char *player;
	char *exit;
	char *collectible;
}				t_img;

typedef struct	s_data 
{
	t_img	img;
	t_mlx mlx;
}				t_data;

bool check_mapname(char *av);

void get_map(t_map *map);

int count_line(t_map map);

void print_map(t_map map);

void free_map(t_map *map);

bool pars_wall(t_map map);

void get_data(t_map *map);

void floodfill(t_map *map, int x, int y);

void init_struct_data(t_data *data);

void set_mlx (t_data *data);