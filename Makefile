NAME = so_long

CC = gcc

lib = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = main.c read_utils.c open_utils.c map_utils.c ft_perror.c solve_map.c clean_utils.c mlx_utils.c input_utils.c display_utils.c
OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -O3 -c $< -o $@

all: lib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_dynamic -lmlx -framework OpenGL -framework AppKit -L./libft -lft -o $(NAME)
	@echo "So long compiled!"

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) $(OBJ)
	make fclean -C libft

lib: 
	make -C libft
