# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 19:07:24 by willda-s          #+#    #+#              #
#    Updated: 2025/04/23 21:06:46 by willda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

INCLUDE = -Iincludes

SRCS_DIR = srcs/

SRCS_FILES = 	main.c \
				init.c \
				utils.c \
				key_handler.c \
				rendering.c

PARSING_DIR = parsing/

PARSING_FILES = parsing.c \
				floodfill.c \
				getmap.c \
				walls.c \
				check.c 

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -MMD -g3

FILE = 	$(addprefix $(SRCS_DIR), $(SRCS_FILES))\
		$(addprefix $(PARSING_DIR), $(PARSING_FILES))\
		
OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(FILE:.c=.o))
DEPD = $(addprefix $(OBJ_DIR), $(FILE:.c=.d))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

all: lib $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(MLX_FLAGS)

$(OBJ_DIR)%.o: %.c Makefile
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

-include $(DEPD)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(MLX_LIB):
	@make -s -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean	
	rm -f $(NAME)      

lib:
	$(MAKE) -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re lib
