/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:30:59 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/19 19:54:31 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	int	j;

	i = 0;
	while (mlx->images[i].size != 0)
	{
		j = 0;
		while (mlx->images[i].sprites[j] != NULL)
		{
			mlx_destroy_image(mlx->mlx, mlx->images[i].sprites[j]);
			j++;
		}
		free(mlx->images[i].sprites);
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
