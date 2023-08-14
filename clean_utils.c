/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:30:59 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/08/14 11:31:01 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_map(void *map)
{
	int		i;
	t_map	*cast;

	cast = (t_map *)map;
	i = 0;
	if (cast->map != NULL)
	{
		while (cast->map[i] != NULL)
		{
			free(cast->map[i]);
			i++;
		}
		free(cast->map);
	}
	free(cast);
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
	if (cast->images != NULL)
		clean_images(cast);
	if (cast->mlx_win != NULL)
		mlx_destroy_window(cast->mlx, cast->mlx_win);
	free(cast);
}

void	clean_game(void *data)
{
	t_game	*cast;

	cast = (t_game *)data;
	clean_map(cast->map);
	clean_mlx(cast->mlx);
}
