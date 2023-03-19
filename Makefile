# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasha <sasha@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:49:10 by hsliu             #+#    #+#              #
#    Updated: 2023/03/19 13:18:45 by sasha            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

MAKE	=	make

SRC_DIR	=	./src/

OBJ_DIR	=	./.obj/

INC_DIR	=	./include/

VPATH	=	./src/parsing ./src/camara ./src/light ./src/vector ./src/exec

LIST_PARSING	=	

LIST_CAMERA		=	

LIST_LIGHT		= 

LIST_VECTOR		= 

LIST_EXEC		=

PARSING_DIR		=	$(addprefix $(SRC_DIR), parsing)

CAMERA_DIR		=	$(addprefix $(SRC_DIR), camera)

LIGHT_DIR		=	$(addprefix $(SRC_DIR), light)

VECTOR_DIR		=	$(addprefix $(SRC_DIR), vector)

EXEC_DIR		=	$(addprefix $(SRC_DIR), exec)

SRC		=	$(addprefix $(PARSING_DIR), $(LIST_PARSING)) \
			$(addprefix $(CAMERA_DIR), $(LIST_CAMERA)) \
			$(addprefix $(LIGHT_DIR), $(LIST_LIGHT)) \
			$(addprefix $(VECTOR_DIR), $(LIST_VECTOR)) \
			$(addprefix $(EXEC_DIR), $(LIST_EXEC))

OBJ		=	$(addprefix $(OBJ_DIR), $(LIST_PARSING:.c=.o)) \
			$(addprefix $(OBJ_DIR), $(LIST_CAMERA:.c=.o)) \
			$(addprefix $(OBJ_DIR), $(LIST_LIGHT:.c=.o)) \
			$(addprefix $(OBJ_DIR), $(LIST_VECTOR:.c=.o)) \
			$(addprefix $(OBJ_DIR), $(LIST_EXEC:.c=.o))

LIST_INC	=	

INC		=	$(addprefix $(INC_DIR), $(LIST_INC))

LIB_DIR	=	libftprintf

LIB		=	libftprintf/libftprintf.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g

all: $(NAME)

$(NAME)	:	$(OBJ_DIR) $(OBJ) $(INC) $(LIB) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) 

$(LIB): $(LIB_DIR)
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR)%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) 

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

clean : 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: clean fclearn re all
