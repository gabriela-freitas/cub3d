# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 20:35:26 by gafreita          #+#    #+#              #
#    Updated: 2023/02/10 20:19:08 by gafreita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#+++++++++ WORKS ON LINUX +++++++++++++ #

NAME = cub3d

SRC_PATH = sources
OBJECTS_NAME = $(SRC_NAME:.c=.o)
CC = cc
INCLUDES = -I /usr/local/include -I ./includes/ -Imlx_linux
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
RM = rm -f
SOURCES = $(wildcard sources/*/*.c) $(wildcard sources/*.c) $(wildcard libft/*.c)  $(wildcard get_next_line/*.c)
OBJECTS = $(SOURCES:.c=.o)
LDLIBS = -g -fsanitize=address #-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
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
