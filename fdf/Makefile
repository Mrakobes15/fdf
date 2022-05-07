# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: risolon <risolon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 21:33:43 by risolon           #+#    #+#              #
#    Updated: 2022/04/09 17:29:58 by risolon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=fdf
SRC=*.c
INCLUDES=minilibx_macos/libmlx.a

all:
	@make -C minilibx_macos/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

push:
	git add .
	git status
	git commit -m fdf
	git push

.PHONY:		all clean fclean re push
