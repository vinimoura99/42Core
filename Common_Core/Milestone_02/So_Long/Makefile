# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/22 18:33:36 by vmoura-d          #+#    #+#              #
#    Updated: 2025/06/22 18:45:26 by vmoura-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                            Makefile para baus_do_guerreiro                   #
# **************************************************************************** #

NAME = so_long

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Fontes do projeto
SRC = main.c game.c map.c render.c events.c utils.c validate_map.c
OBJ = $(SRC:.c=.o)

# Caminho e uso da MiniLibX
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

# Compilação principal
all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

# Compilar a MLX padrão (ignora os testes se libbsd não estiver instalada)
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR) all

# Limpar objetos do projeto
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean || true

# Limpeza completa
fclean: clean
	rm -f $(NAME)

# Recompilar tudo
re: fclean all

.PHONY: all clean fclean re
