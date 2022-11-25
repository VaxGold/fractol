# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omercade <omercade@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 16:11:54 by omercade          #+#    #+#              #
#    Updated: 2021/08/23 18:28:12 by omercade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3
LIBRARIES = -lmlx -lm -lft\
	-L$(LIBFT_DIRECTORY)\
	-framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_DIRECTORY)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/

HEADERS_LIST = fractol.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./srcs/
SOURCES_LIST = key_input.c \
				mouse_input.c \
				print_help.c \
				draw_fractal.c \
				get_color.c \
				init_complex.c \
				get_complex.c \
				set_default.c \
				close_window.c \
				fractal_julia.c \
				fractal_mandelbrot.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST)) \
			fractol.c
			
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
BLUE = \033[0;36m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) fractol.c -o $(NAME)
	@echo "\n$(BLUE)OBJECT FILES WERE CREATED!$(RESET)"
	@echo "$(GREEN)PROGRAM $(NAME) WAS CREATED SUCCESSFULLY!!$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(BLUE)DIRECTORY $(OBJECTS_DIRECTORY) WAS CREATED!$(RESET)"
	@echo "$(BLUE)CREATING OBJECTS...$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN)✓$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(BLUE)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIRECTORY) all


clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(RED)DIRECTORY $(OBJECTS_DIRECTORY) WAS DELETED!$(RESET)"
	@echo "$(RED)OBJECTS FILES WERE DELETED!$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(RED)$(LIBFT) WAS DELETED!$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)PROGRAM $(NAME) WAS DELETED!!$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
