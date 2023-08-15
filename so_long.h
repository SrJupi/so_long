/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:42:37 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/04/13 11:37:04 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
//# include <X11/keysym.h>
//# include <X11/X.h>
# include <mlx.h>
# include "libft/libft.h"
# define EXTENSION ".ber"
# define MAP_FOLDER "maps/"
# define VALID_CHAR "01CEP"
# define C 2
# define E 3
# define P 4
# define SCREEN_W 15
# define SCREEN_H 9
# define SCREEN_B 3
# define IMG_SIZE 32

typedef struct s_map
{
	char	**map;
	char	**copy_map;
	size_t	col;
	size_t	lin;
	size_t	player;
	size_t	collect;
	size_t	exit;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	**images;
	int		img_w;
	int		img_h;
}	t_mlx;

typedef struct s_coord
{
	int	x;
	int	y;
	int	info;
}	t_coord;

typedef struct s_game
{
	t_mlx		*mlx;
	t_map		*map;
	t_coord		player;
	t_coord		screen;
}	t_game;

//Open + Read functions
int		ft_open(char *filename);
char	*ft_strcat(char *s1, char *s2, int clean_it);
char	**ft_read(int fd);

//Map creation and check functions
void	create_map(t_game *map, char *str);
void	check_closed(t_map *map);
void	check_valid_char(t_game *data);

void	solve_map(t_game *map);

//Mlx creation
void	create_mlx(t_game *data);

//Input functions
int		handle_keypress(int key, t_game *data);
int		close_window(t_game *data);

//Display functions
int		draw_map(t_game *data);

//Error functions
void	ft_perror(int err, char *str);
void	ft_error(int err, char *msg, void (*clean_func)(void *), void *data);

//Clean functions
void	clean_array(void *array);
void	clean_map(void *map);
void	clean_game(void *data);

#endif
