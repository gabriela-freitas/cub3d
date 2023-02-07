# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 20:35:26 by gafreita          #+#    #+#              #
#    Updated: 2023/02/07 19:49:21 by dmendonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#+++++++++ WORKS ON LINUX +++++++++++++ #

NAME = cub3d

SRC_PATH = sources
OBJECTS_NAME = $(SRC_NAME:.c=.o)
CC = gcc
CFLAGS = -I /usr/local/include
RM = rm -f
SOURCES = $(wildcard sources/*/*.c) $(wildcard sources/*.c) $(wildcard libft/*.c)  $(wildcard get_next_line/*.c)
OBJECTS = $(SOURCES:.c=.o)
LDLIBS = -g -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm #-fsanitize=address
BLUE = \033[34m
YELL = \033[33m
WHITE = \033[0m
GREEN = \033[32m

all: $(NAME)
	
%.o: %.c
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJECTS)
	-@$(CC) $(OBJECTS) $(LDLIBS) -o $(NAME)

clean:
	@$(RM) $(OBJECTS)
	@echo -e "$(GREEN)OBJECTS DELETED$(WHITE)"

fclean:
	@rm -f $(NAME)
	@echo -e "\n$(GREEN)FRACTOL ERASED$(WHITE)"

re: fclean all

.PHONY: all clean fclean re submodule
