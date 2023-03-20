NAME = so_long

CC = gcc

lib = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = main.c read_utils.c open_utils.c map_utils.c ft_perror.c solve_map.c
OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: lib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L./libft -lft -o $(NAME)
	@echo "So long compiled!"

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) $(OBJ)
	make fclean -C libft

lib: 
	make -C libft
