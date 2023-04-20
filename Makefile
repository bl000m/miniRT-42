# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathia <mathia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:49:10 by hsliu             #+#    #+#              #
#    Updated: 2023/04/20 21:28:27 by mathia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

MAKE	=	make

SRC_DIR	=	./src/

OBJ_DIR	=	./.obj/

INC_DIR	=	./include/

VPATH	=	./src/parsing ./src/camera ./src/light ./src/world ./src/exec

LIST_PARSING	=	reading_rt.c scanning_rt.c init_instructions.c parsing_utils.c\
					ft_redef_space.c

LIST_CAMERA		=	ft_camera_ray.c hit_sphere.c ray_op.c \
					hit_cyl.c hit_cyl_helper.c hit_plane.c ft_hit.c \
					ft_ambient_light.c ft_spec_light.c

LIST_WORLD		= 	list_op1.c math_utils.c matrix_op.c \
					vector_op1.c vector_op2.c vector_op3.c \
					color.c

LIST_EXEC		=	main.c hooks.c init.c settings.c memory_error.c

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

LIST_INC	=	parsing.h camera.h world.h exec.h scene.h

INC		=	$(addprefix $(INC_DIR), $(LIST_INC))

# library minilibx
MLX_DIR		= mlx_linux
MLX			= $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_Linux.a
MLX_INC		= -Imlx_linux
MLX_LNK		= -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# library ft_
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_INC	= -Ilibft
LIBFT_LNK	= -Llibft -l ft

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(INC) $(MLX) $(LIBFT)
	$(CC) $(OBJ) $(MLX_LNK) $(MLX_INC) $(LIBFT_LNK) $(LIBFT_INC) -o $(NAME)

$(MLX): $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)


$(OBJ_DIR)%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I/usr/include $(MLX_INC) $(LIBFT_INC) -I $(INC_DIR) -O3 -c $< -o $@

$(LIBFT):	FORCE
	make -C $(LIBFT_DIR)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

FORCE	:

val :
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./miniRT ./scene/simple.rt

clean :
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: clean fclearn re all
