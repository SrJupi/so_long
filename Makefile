NAME = so_long
BONUS = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD

# External libraries
ft = libft/libft.a
mlx = mlx/libmlx.a  

# Folders
SRC_DIR = src
OBJ_DIR = obj
DEP_DIR = dep
INC_DIR = inc

# Source files
SRC = main.c read_utils.c open_utils.c map_utils.c \
	ft_perror.c solve_map.c clean_utils.c mlx_utils.c \
	input_utils.c display_utils.c check_map.c image_utils.c \
	check_closed.c copy_map.c

# Object files
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DEP = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

# Compile SRC files and move to folders
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/so_long.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -Imlx -Ilibft -I$(INC_DIR) -O3 -c $< -o $@
	@mkdir -p $(DEP_DIR)
	@mv $(OBJ_DIR)/$*.d $(DEP_DIR)/

all: lib libmlx $(NAME)

$(NAME): $(OBJ) $(ft) $(mlx)
	$(CC) $(OBJ) -L./mlx -lmlx -framework OpenGL -framework AppKit -L./libft -lft -o $(NAME)
	@echo "So long compiled!"

lib: 
	make -C libft

libmlx:
	make -C mlx

clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)
	make clean -C libft

fclean:
	rm -rf $(NAME) $(OBJ_DIR) $(DEP_DIR)
	make fclean -C libft
	make clean -C mlx	

re:	fclean all

-include $(DEP)

.PHONY: all re clean fclean