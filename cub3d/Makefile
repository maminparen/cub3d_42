# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzona <hzona@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 17:34:09 by crow              #+#    #+#              #
#    Updated: 2021/12/28 13:35:06 by hzona            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

SRCS_DIR	=	src/

SRC			=	main/cub3d.c \
				main/cub_init.c \
				mlx/cub_draw.c \
				mlx/cub_hook.c \
				mlx/cub_draw_wall.c \
				mlx/cub_draw_wall2.c \
				mlx/cub_draw_sprite.c \
				mlx/cub_draw_minimap.c \
				mlx/cub_draw_check_sprite.c \
				mlx/cub_draw_check_door.c \
				mlx/update_move.c \
				parsing/parsing.c \
				parsing/parsing_texture.c \
				parsing/parsing_texture_sprite.c \
				parsing/parsing_texture_main.c \
				parsing/parsing_read_map.c \
				parsing/parsing_read_line.c \
				parsing/parsing_list_to_array.c \
				parsing/parsing_check_map_circuit.c \
				utils/cub_print.c \
				utils/cub_utils.c


OBJS		=	${addprefix ${SRCS_DIR}, ${SRC:.c=.o}}

HEADER		= 	include/cub3d.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

LIBFT_LIB	=	libft.a
LIBFT_DIR	=	./libft/
LIBFT_INC	=	-I ${LIBFT_DIR}
LIBFT		=	${LIBFT_DIR}${LIBFT_LIB}

MLX_LIB		=	libmlx.a
MLX_DIR		=	./mlx/
MLX_INC		=	-I ${MLX_DIR}
MLX			=	-L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

RM			=	rm -f

#COLORS
C_NO		=	"\033[00m"
C_OK		=	"\033[32m"
C_GOOD		=	"\033[32m"
SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)

%.o			:	%.c	${HEADER}
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}		:	${OBJS} ${HEADER} Makefile
#				@make -C ${MLX_DIR} all
#				@echo "\tCompiling...\t" [ $(MLX_LIB) ] $(SUCCESS)
#				@make -C ${LIBFT_DIR} all
				${CC} ${OBJS} -o ${NAME} ${LIBFT} ${MLX} 
				@echo "\tCompiling...\t" [ $(NAME) ] $(SUCCESS)

all 		:	$(NAME)

bonus		:	$(NAME)

clean:
#				@make -C ${LIBFT_DIR} clean
#				@make -C ${MLX_DIR} clean > /dev/null	
#				@echo "\tCleaning...\t" [ $(MLX_LIB) ] $(OK)	
				@${RM} $(OBJS)
				@echo "\tCleaning...\t" [ $(NAME) ] $(OK)

fclean: 		
#				@make -C ${LIBFT_DIR} fclean
#				@make -C ${MLX_DIR}/ clean > /dev/null
#				@echo "\tCleaning...\t" [ $(MLX_LIB) ] $(OK)
				@${RM} $(OBJS) $(NAME)
				@echo "\tDeleting...\t" [ $(NAME) ] $(OK)	

re: 			fclean all

.PHONY: 		all re clean fclean libs
