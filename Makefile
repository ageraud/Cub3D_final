# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 16:10:29 by agathe            #+#    #+#              #
#    Updated: 2020/09/17 17:19:42 by agathe           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc

INCLUDES	=	includes/cub.h

MLX			= 	minilibx/libmlx.a

SRC 		= 	get_next_line.c 				\
				get_next_line_utils.c 			\
				libft_calloc_atoi.c				\
				libft_split.c					\
				libft_utils.c					\
				parse_convert_texture_to_img.c	\
				bmp_screenshot.c				\
				parse_start_main.c				\
				parse_init.c					\
				parse_global_loop.c				\
				parse_join_line_map.c			\
				parse_texture.c					\
				parse_color.c					\
				parse_check_elem.c				\
				parse_alloc_map.c				\
				parse_check_valid_map.c			\
				parse_end_start_cub3d.c			\
				ray_start.c						\
				ray_define_move.c				\
				ray_close_window_free_tab.c		\
				ray_loop.c						\
				ray_loop_print_wall.c			\
				ray_key_values.c				\
				ray_sprite.c					\
				ray_draw_sprite.c				\
				ray_init.c						\
				parse_resolution.c				\
				parse_check_map_char.c			\
				parse_compare_line_diff.c		\

PATH_SRC	=	srcs/

PATH_OBJ	=	objs/

OBJ 		= 	$(addprefix $(PATH_OBJ), $(SRC:.c=.o))

NAME 		= 	Cub3D

RM			= 	rm -rf

CFLAGS 		= 	-Wall -Wextra -Werror

ADDFLAG		=	-I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit

all: 			$(MLX) $(NAME)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(INCLUDES)
				@mkdir -p $(PATH_OBJ)
				${CC} ${CFLAGS} -c $< -o $@

$(NAME):		$(OBJ) $(INCLUDES)
				$(CC) $(CFLAGS) $(ADDFLAG) $(OBJ) -o $(NAME)

$(MLX): 
				@$(MAKE) -C minilibx all

clean:			
				@$(MAKE) -C minilibx clean
				@$(RM) $(PATH_OBJ)
				$(RM) screenshot.bmp
				
fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all
.PHONY: 		clean fclean