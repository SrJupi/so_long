NAME = so_long

CC = gcc

lib = libft/libft.a

libmlx = mlx/libmlx.a 

CFLAGS = -Wall -Wextra -Werror

SRC = main.c read_utils.c open_utils.c map_utils.c ft_perror.c solve_map.c clean_utils.c mlx_utils.c input_utils.c display_utils.c check_map.c image_utils.c
OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(libmlx) $(lib) $(OBJ)
	$(CC) $(OBJ) -L./mlx -lmlx -framework OpenGL -framework AppKit -L./libft -lft -o $(NAME)
	@echo "So long compiled!"

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean:
	rm -rf $(NAME) $(OBJ)
	make fclean -C libft
	make clean -C mlx

$(lib): 
	make -C libft

$(libmlx):
	make -C mlx

re:	fclean all

.PHONY: all re clean fclean