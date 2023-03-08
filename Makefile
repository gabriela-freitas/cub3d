# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 20:35:26 by gafreita          #+#    #+#              #
#    Updated: 2023/03/08 18:32:07 by dmendonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#+++++++++ WORKS ON LINUX +++++++++++++ #

NAME = cub3d

SRC_PATH = sources
OBJECTS_NAME = $(SRC_NAME:.c=.o)
CC = cc
INCLUDES = -I /usr/local/include -I ./includes/ -Imlx_linux
CFLAGS = -g -Wall -Wextra -Werror $(INCLUDES)
RM = rm -f
SOURCES =	./sources/math/calculators.c \
			./sources/math/math.c \
			./sources/math/init_direction.c \
			./sources/main.c \
			./sources/game/drawing.c \
			./sources/game/window_management.c \
			./sources/game/movement.c \
			./sources/game/rotation.c \
			./sources/parsing/map_parser.c \
			./sources/parsing/read_file.c \
			./sources/parsing/zeros_test.c \
			./sources/parsing/burn_map.c \
			./sources/parsing/get_file_info.c \
			./sources/parsing/utils.c \
			./sources/parsing/map_checker.c \
			./sources/libft/ft_atoi.c \
			./sources/libft/ft_strdup.c \
			./sources/libft/ft_strncmp.c \
			./sources/libft/ft_isspace.c \
			./sources/libft/ft_strrchr.c \
			./sources/libft/ft_strlen.c \
			./sources/libft/ft_strchr.c \
			./sources/libft/ft_substr.c \
			./sources/libft/ft_split.c \
			./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \

OBJECTS = $(SOURCES:.c=.o)
LDLIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -g #-fsanitize=address
BLUE = \033[34m
YELL = \033[33m
WHITE = \033[0m
GREEN = \033[32m

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -O3 -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) is ready to use$(WHITE)"

clean:
	@$(RM) $(OBJECTS)
	@echo "$(GREEN)OBJECTS DELETED$(WHITE)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) ERASED$(WHITE)"

re: fclean all


.PHONY: all clean fclean re
