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
# include "libft/libft.h"
# define EXTENSION ".ber"
# define MAP_FOLDER "maps/"
# define VALID_CHAR "01CEP"

typedef struct t_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct t_map
{
	char	**map;
	size_t	col;
	size_t	lin;
	size_t	player;
	size_t	collect;
	size_t	exit;
}	t_map;

typedef struct t_char
{
	void	**numbers;
	void	**letters;
	void	**points;
}	t_char;

int		ft_open(char *filename);
char	*ft_strcat(char *s1, char *s2);
char	**ft_read(int fd);
void	ft_perror(int err, char *str);

#endif
