NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD

ft = libft/libft.a

mlx = mlx/libmlx.a  

SRC = main.c read_utils.c open_utils.c map_utils.c ft_perror.c solve_map.c clean_utils.c mlx_utils.c input_utils.c display_utils.c check_map.c image_utils.c check_closed.c

OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -Ilibft -O3 -c $< -o $@

all: lib libmlx $(NAME)

$(NAME): $(OBJ) $(ft) $(mlx)
	$(CC) $(OBJ) -L./mlx -lmlx -framework OpenGL -framework AppKit -L./libft -lft -o $(NAME)
	@echo "So long compiled!"


lib: 
	make -C libft

libmlx:
	make -C mlx

clean:
	rm -rf $(OBJ) $(DEP)
	make clean -C libft

fclean:
	rm -rf $(NAME) $(OBJ) $(DEP)
	make fclean -C libft
	make clean -C mlx	

re:	fclean all

-include $(DEP)

.PHONY: all re clean fclean