# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasha <sasha@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:49:10 by hsliu             #+#    #+#              #
#    Updated: 2023/03/27 13:38:47 by sasha            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

MAKE	=	make

SRC_DIR	=	./src/

OBJ_DIR	=	./.obj/

INC_DIR	=	./include/

VPATH	=	./src/parsing ./src/camera ./src/light ./src/world ./src/exec

LIST_PARSING	=	

LIST_CAMERA		=	ft_camera_ray.c hit_sphere.c ray_op.c 

LIST_LIGHT		= 

LIST_WORLD		= 	list_op1.c math_utils.c matrix_op.c \
					vector_op1.c vector_op2.c vector_op3.c 

LIST_EXEC		=	main.c hooks.c init.c

PARSING_DIR		=	$(addprefix $(SRC_DIR), parsing)

CAMERA_DIR		=	$(addprefix $(SRC_DIR), camera)

LIGHT_DIR		=	$(addprefix $(SRC_DIR), light)

VECTOR_DIR		=	$(addprefix $(SRC_DIR), world)

EXEC_DIR		=	$(addprefix $(SRC_DIR), exec)

SRC		=	$(addprefix $(PARSING_DIR), $(LIST_PARSING)) \
			$(addprefix $(CAMERA_DIR), $(LIST_CAMERA)) \
			$(addprefix $(LIGHT_DIR), $(LIST_LIGHT)) \
			$(addprefix $(WORLD_DIR), $(LIST_WORLD)) \
			$(addprefix $(EXEC_DIR), $(LIST_EXEC))

OBJ		=	$(addprefix $(OBJ_DIR), $(LIST_PARSING:.c=.o)) \
			$(addprefix $(OBJ_DIR), $(LIST_CAMERA:.c=.o)) \
			$(addprefix $(OBJ_DIR), $(LIST_LIGHT:.c=.o)) \
			$(addprefix $(OBJ_DIR), $(LIST_WORLD:.c=.o)) \
			$(addprefix $(OBJ_DIR), $(LIST_EXEC:.c=.o))

LIST_INC	=	parsing.h camera.h world.h exec.h

INC		=	$(addprefix $(INC_DIR), $(LIST_INC))

MLX_DIR	=	mlx_linux

MLX		=	 mlx_linux/libmlx.a mlx_linux/libmlx_Linux.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(INC) $(MLX)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(MLX): $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -I $(INC_DIR) -O3 -c $< -o $@

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

clean : 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: clean fclearn re all
