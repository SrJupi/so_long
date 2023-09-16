/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:30:59 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/08/30 18:04:21 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_array(void *array)
{
	int		i;
	char	**cast;

	cast = (char **)array;
	i = 0;
	if (cast != NULL)
	{
		while (cast[i] != NULL)
		{
			free(cast[i]);
			i++;
		}
		free(cast);
		cast = NULL;
	}
}

void	clean_map(void *map)
{
	t_map	*cast;

	cast = (t_map *)map;
	if (cast != NULL)
	{
		if (cast->map != NULL)
			clean_array(cast->map);
		free(cast);
	}
}

void	clean_images(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->images[i] != NULL)
	{
		mlx_destroy_image(mlx->mlx, mlx->images[i]);
		i++;
	}
	free(mlx->images);
}

void	clean_mlx(void *mlx)
{
	t_mlx	*cast;

	cast = (t_mlx *)mlx;
	if (cast != NULL)
	{
		ft_putstr_fd("clean mlx\n",1);
		if (cast->images != NULL)
			clean_images(cast);
		if (cast->mlx_win != NULL)
			mlx_destroy_window(cast->mlx, cast->mlx_win);
		free(cast);
	}
}

void	clean_game(void *data)
{
	t_game	*cast;

	cast = (t_game *)data;
	if (cast != NULL)
	{
		clean_map(cast->map);
		clean_mlx(cast->mlx);
	}
}
