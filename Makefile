MAKEFLAGS = --no-print-directory

### colors ###
RESET =  \033[0m
BOLD =   \033[1m
RED =    \033[31m
GREEN =  \033[32m
YELLOW = \033[33m
##############

NAME = miniRT

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/ libft/includes minilibx-linux/

LIBS = -L./minilibx-linux -lmlx -L./libft -lm -lXext -lX11 -lft
LIBSDEP = ./libft/libft.a ./minilibx-linux/libmlx_Linux.a

SRC_FILES = additional_functions_for_parsing.c \
			bmp.c \
			check_argument.c \
			check_line_1.c \
			check_line_2.c \
			cylinder.c \
			cylinder2.c \
			ft_lstadd_back2.c \
			ft_lstclear2.c \
			lighting.c \
			lighting2.c \
			lighting3.c \
			lighting4.c \
			linear_algebra.c \
			linear_algebra2.c \
			main.c \
			math_function.c \
			parser_environment.c \
			parser_figure.c \
			parser_scene.c \
			plane.c \
			raytracing.c \
			render.c \
			rotation.c \
			scene.c \
			sphere.c \
			square.c \
			triangle.c \
			display.c \
			save.c \
			get_image.c

OBJ_FILES = $(SRC_FILES:.c=.o)
DEP_FILES = $(SRC_FILES:.c=.d)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP = $(addprefix $(OBJ_DIR), $(DEP_FILES))

INC = $(addprefix -I, $(INC_DIR))

all: libs $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBSDEP) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $^ -o $@  $(LIBS)
	@echo "$(YELLOW)$(BOLD)$(NAME) created!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(INC) $(CFLAGS) -c $< -o $@ -MMD
 
 libs:
	@$(MAKE) -C libft/
	@$(MAKE) -C minilibx-linux/

-include $(DEP)

clean:
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C minilibx-linux/ clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)
	@echo "$(RED)$(BOLD)$(NAME) deleted!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
