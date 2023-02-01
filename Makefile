# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 20:35:26 by gafreita          #+#    #+#              #
#    Updated: 2023/02/01 19:25:14 by gafreita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#+++++++++ WORKS ON LINUX +++++++++++++ #

NAME = cub3d
SRCS =	sources/main.c \
OBJS = $(patsubst sources/%.c, $(OBJS_PATH)%.o, $(SRCS))
OBJS_PATH = objs/
DEPS	= ../LIBFT/libft.a ../mlx_linux/libmlx.a


CCFLAGS = gcc -Wall -Wextra -Werror -g

#directories with .a
LIBFT_LIB_DIR = ../LIBFT/
MLX_LIB_DIR = ../mlx_linux/

#directories with .h
LIBFT_INCLUDE = -I ../LIBFT/include -I .
MLX_INCLUDE = -I ../mlx_linux

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

MLX_FLAGS = -L $(MLX_LIB_DIR) -lmlx -lXext -lX11 -lm -lz

# ^ primeira dependencia
# @ nome da regra
all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS) $(DEPS)
	@$(CCFLAGS) $(OBJS) $(LIBFT_INCLUDE) $(MLX_INCLUDE) -L$(LIBFT_LIB_DIR) -lft $(MLX_FLAGS) -o $(@)
#@mv $(OBJS) objs/
	@echo "$(COLOUR_YELLOW) >>> OBJECTS DIRECTORY CREATED <<< $(COLOUR_END)"
	@echo "$(COLOUR_GREEN) >>> SO_LONG READY <<< $(COLOUR_END)"
submodule:
	@git submodule update --init --recursive


$(OBJS_PATH)%.o: sources/%.c
	@$(CCFLAGS) $(LIBFT_INCLUDE) $(MLX_INCLUDE) -c $(^) -o $(@)

../mlx_linux/libmlx.a:
	@make -s -C $(MLX_LIB_DIR)
	@echo "$(COLOUR_GREEN) >>> MLX OK <<< $(COLOUR_END)"

../LIBFT/libft.a:
	@make -s -C $(LIBFT_LIB_DIR)

$(OBJS_PATH):
	@mkdir -p objs

clean:
	@make clean -s -C $(LIBFT_LIB_DIR)
	@rm -rf $(OBJS_PATH)

fclean: clean
	@make fclean -s -C $(LIBFT_LIB_DIR)
	@rm -f $(NAME)
	@echo "$(COLOUR_YELLOW) SO_LONG CLEANED $(COLOUR_END)"

re: fclean all

test: all
	@echo "Executing so_long"
	@./$(NAME) map.ber

.PHONY: all clean fclean re submodule
