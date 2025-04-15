# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 19:07:24 by willda-s          #+#    #+#              #
#    Updated: 2025/04/11 00:39:33 by willda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

INCLUDE = -Iincludes

SRCS_DIR = srcs/

SRCS_FILES = 	main.c \
				init.c \
				utils.c \
				key_handler.c

PARSING_DIR = PARSING/

PARSING_FILES = parsing.c \
				floodfill.c \
				mapcheck.c \
				parsing2.c 

GNL_DIR = GNL/

GNL_FILES = get_next_line.c \
			get_next_line_utils.c \

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -MMD -g3

FILE = 	$(addprefix $(SRCS_DIR), $(SRCS_FILES))\
		$(addprefix $(PARSING_DIR), $(PARSING_FILES))\
		$(addprefix $(GNL_DIR), $(GNL_FILES))\
		
OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(FILE:.c=.o))
DEPD = $(addprefix $(OBJ_DIR), $(FILE:.c=.d))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

$(OBJ_DIR)%.o: %.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX_LIB)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(PRINTF) $(MLX_FLAGS)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(PRINTF):
	@make -s -C $(PRINTF_DIR)


$(MLX_LIB):
	@make -s -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)



fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean	
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)      

re: fclean all

-include $(DEPD)

.PHONY: all clean fclean re
