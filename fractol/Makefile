# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 17:13:29 by ckarl             #+#    #+#              #
#    Updated: 2023/04/08 23:48:50 by ckarl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c hooks.c mandelbrot.c julia.c image.c

OBJS			= ${SRCS:.c=.o}

HEADER  		= fractol.h

LIBS			= -Llibft -Lmlx -lft -lmlx -framework OpenGL -framework AppKit

OTH_HEAD		= -Ilibft -Imlx

NAME			= fractol

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror -g

RM				= rm -f

COLOUR_GREEN	=\033[1;32m
COLOUR_RED		=\033[0;31m
COLOUR_YELL		=\033[0;33m
COLOUR_TURQ		=\033[1;36m
COLOUR_WHITE	=\033[1;37m
COLOUR_BLUE		=\033[1;34m
COLOUR_VIO		=\033[1;35m
COLOUR_END		=\033[0m

%.o: %.c
				${CC} -c ${CFLAGS} $< -o $@

all:			${NAME}

${NAME}:		${OBJS}
				cd mlx; make all
				cd libft; make all
				${CC} ${CFLAGS} -o $@ ${OBJS} ${LIBS} ${OTH_HEAD}
				@echo "$(COLOUR_BLUE)Compilation successful!$(COLOUR_END)"

clean:
				${RM} ${OBJS}
				cd mlx; make clean
				cd libft; make clean
				@echo "$(COLOUR_GREEN)All clear!$(COLOUR_END)"

fclean:			clean
				${RM} ${NAME}
				cd libft; make fclean
				@echo "$(COLOUR_VIO)All clear clear!$(COLOUR_END)"

re:				fclean all

.PHONY:			all clean fclean re
