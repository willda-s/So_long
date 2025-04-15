/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:22:05 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/15 17:59:57 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "fcntl.h"
#include "../GNL/get_next_line.h"
#include "math.h"
#include "errno.h"
#include <X11/keysym.h>
#include <X11/X.h>

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
	int exit_x;
	int exit_y;
}		t_map;

typedef struct s_mlx
{
	void *ptr;
	void *win;
	void *imgfloor;
	void *imgwall;
	void *imgplayer;
	void *imgexitclose;
	void *imgexitopen;
	void *imgcollectible;
	int width;
	int height;
}				t_mlx;

typedef struct s_img
{
	char *floor;
	char *wall;
	char *player;
	char *exitclose;
	char *exitopen;
	char *collectible;
}				t_img;

typedef struct	s_data 
{
	t_img	img;
	t_mlx mlx;
	t_map map;
}				t_data;

/////////////////////// UTILS ///////////////////

void print_map(t_data data);

void free_and_exit(t_data *data, char *err);

void free_map(t_data *data);

void free_tab(char **tab);

void exitmlx(t_data *data, char *err);

/////////////////////// PARSING ///////////////////

bool check_mapname(char *av);

void get_map(t_data *data);

int count_line(t_data data);

bool pars_wall(t_data data);

void get_data(t_data *data);

void floodfill(char **dst, int player_x, int player_y, t_data *data);

char **map_double(t_data data);

/////////////////////// INIT ////////////////////

void init_struct_data(t_data *data);

void init_struct_map(t_data *data, char **av);

void set_mlx (t_data *data);

void	my_mlx_put_image_to_window(t_data data, int i, int j, void *img);

int keyhandler(t_data *data, int keycode);