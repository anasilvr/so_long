# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 16:12:54 by anarodri          #+#    #+#              #
#    Updated: 2023/04/17 15:05:45 by anarodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g
#INCLUDE	= ./libft/libft.a
INCLUDE	=	-framework OpenGL -framework AppKit ./mlx/libmlx.a ./libft/libft.a
RM		=	@rm -rf
# /usr/local/include/mlx.h

SRC		=	$(addprefix src/, events.c main.c map_validation.c move.c load.c rendering.c so_long.c utils.c gameplay.c)

OBJ		=	$(SRC:.c=.o)

#%.o:		%.c
#			$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@echo "			-> Compiling $(NAME)..."
			@$(MAKE) -C ./libft
			$(CC) $(FLAGS) $(OBJ) $(INCLUDE) -o $(NAME)
			@echo "			Compiled!"

clean:
			@echo "			-> Removing object files..."
			@$(MAKE) -C libft fclean
			@$(RM) -f $(OBJ)
			@echo "			OK!"

fclean:		clean
			@echo "			-> Removing $(NAME)..."
			@$(RM) -f $(NAME)
			@echo "			OK!"

re:			fclean all

test:
			./test.sh

norm:
			norminette $(SRC) *.h */*.h

.PHONY:		all clean fclean re test norm