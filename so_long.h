/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:42:37 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/02/15 12:42:09 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/keysym.h>
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
# define IMG_SIZE 32

typedef struct s_map
{
	char	**map;
	size_t	col;
	size_t	lin;
	size_t	player;
	size_t	collect;
	size_t	exit;
	int		f_x;
	int		f_y;
	int		p_x;
	int		p_y;
	int		update;
}	t_map;

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	**images;
	int		img_w;
	int		img_h;
/*	void	*wall;
	void	*player;
	void	*exit;
	void	*collect;
	void	*back;
	void	*empty;*/
} t_mlx;

typedef struct	s_game
{
	t_mlx	*mlx;
	t_map	*map;
} t_game;

//Open + Read functions
int		ft_open(char *filename);
char	*ft_strcat(char *s1, char *s2);
char	**ft_read(int fd);

//Map creation and check functions
void	create_map(t_map **map, char *str);
void	solve_map(t_map *map);

//Mlx creation
void	create_mlx(t_game *data);

//Error functions
void	ft_perror(int err, char *str);
void	ft_error(int err, char *msg, void (*clean_func)(void *), void *data);

//Clean functions
void	clean_map(void *map);
void	clean_game(void *data);

#endif
