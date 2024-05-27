NAME = so_long
BONUS = so_long_bonus

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

SRC_BDIR = src_bonus
OBJ_BDIR = obj_bonus
DEP_BDIR = dep_bonus

# Source files
SRC = main.c read_utils.c open_utils.c map_utils.c \
	ft_perror.c solve_map.c clean_utils.c mlx_utils.c \
	input_utils.c display_utils.c check_map.c image_utils.c \
	check_closed.c copy_map.c

SRC_B = main_bonus.c read_utils_bonus.c open_utils_bonus.c map_utils_bonus.c \
	ft_perror_bonus.c solve_map_bonus.c clean_utils_bonus.c mlx_utils_bonus.c \
	input_utils_bonus.c display_utils_bonus.c check_map_bonus.c image1_utils_bonus.c \
	check_closed_bonus.c copy_map_bonus.c sprite_utils_bonus.c time_bonus.c \
	sprite1_bonus.c sprite2_bonus.c image2_utils_bonus.c

# Object files
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DEP = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

OBJ_B = $(addprefix $(OBJ_BDIR)/,$(SRC_B:.c=.o))
DEP_B = $(addprefix $(OBJ_BDIR)/,$(SRC_B:.c=.d))

# Compile SRC files and move to folders
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -Imlx -Ilibft -I$(INC_DIR) -O3 -c $< -o $@
	@mkdir -p $(DEP_DIR)
	@mv $(OBJ_DIR)/$*.d $(DEP_DIR)/

$(OBJ_BDIR)/%.o : $(SRC_BDIR)/%.c
	@mkdir -p $(OBJ_BDIR)
	$(CC) $(CFLAGS) -Imlx -Ilibft -I$(INC_DIR) -O3 -c $< -o $@
	@mkdir -p $(DEP_BDIR)
	@mv $(OBJ_BDIR)/$*.d $(DEP_BDIR)/

all: lib libmlx $(NAME)

bonus: lib libmlx $(BONUS)

$(NAME): $(OBJ) $(ft) $(mlx)
	$(CC) $(OBJ) -L./mlx -lmlx -framework OpenGL -framework AppKit -L./libft -lft -o $(NAME)
	@echo "So long compiled!"

$(BONUS): $(OBJ_B) $(ft) $(mlx)
	$(CC) $(OBJ_B) -L./mlx -lmlx -framework OpenGL -framework AppKit -L./libft -lft -o $(BONUS)
	@echo "Bonus compiled!"

lib: 
	make -C libft

libmlx:
	make -C mlx

clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR) $(OBJ_BDIR) $(DEP_BDIR)
	make clean -C libft

clean_bonus:
	rm -rf $(OBJ_BDIR) $(DEP_BDIR)
	make clean -C libft

fclean:
	rm -rf $(NAME) $(OBJ_DIR) $(DEP_DIR) $(OBJ_BDIR) $(DEP_BDIR)
	make fclean -C libft
	make clean -C mlx	

fclean_bonus:
	rm -rf $(BONUS) $(OBJ_BDIR) $(DEP_BDIR)
	make fclean -C libft
	make clean -C mlx	

re:	fclean all

-include $(DEP)

.PHONY: all re clean fclean