# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoura-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 11:27:02 by vmoura-d          #+#    #+#              #
#    Updated: 2025/04/28 11:27:15 by vmoura-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

# Project name
NAME = libftprintf.a
MAIN = main.c

# Source and object files
SRC_DIR = srcs
OBJ_DIR = objs

SRCS = ft_printf.c $(SRC_DIR)/ft_printf_float.c $(SRC_DIR)/ft_printf_formats.c $(SRC_DIR)/ft_printf_utils.c
OBJS = $(OBJ_DIR)/ft_printf.o $(OBJ_DIR)/ft_printf_utils.o $(OBJ_DIR)/ft_printf_formats.o $(OBJ_DIR)/ft_printf_float.o

# All rule
all: $(NAME)

# Create the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile main.o (the object file for your main.c)
$(OBJ_DIR)/main.o: $(MAIN) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(MAIN) -o $(OBJ_DIR)/main.o

# Create the executable by linking main.o with the static library
libftprintf_test: $(OBJ_DIR)/main.o $(OBJS)
	$(CC) $(CFLAGS) -o libftprintf_test $(OBJ_DIR)/main.o $(OBJS)

# Clean object files
clean:
	rm -f $(OBJS) $(OBJ_DIR)/main.o

# Clean all
fclean: clean
	rm -f $(NAME) libftprintf_test

# Rebuild the project
re: fclean all

# Ensure the object directory exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Manually compile each source file into an object file
$(OBJ_DIR)/ft_printf.o: ft_printf.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c ft_printf.c -o $(OBJ_DIR)/ft_printf.o

$(OBJ_DIR)/ft_printf_utils.o: $(SRC_DIR)/ft_printf_utils.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ft_printf_utils.c -o $(OBJ_DIR)/ft_printf_utils.o

$(OBJ_DIR)/ft_printf_formats.o: $(SRC_DIR)/ft_printf_formats.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ft_printf_formats.c -o $(OBJ_DIR)/ft_printf_formats.o

$(OBJ_DIR)/ft_printf_float.o: $(SRC_DIR)/ft_printf_float.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ft_printf_float.c -o $(OBJ_DIR)/ft_printf_float.o

