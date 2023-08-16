/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:21:51 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/08/16 10:29:20 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_collectable(t_game *data, int j, int i)
{
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win,
		data->mlx->images[2],
		j * IMG_SIZE,
		i * IMG_SIZE);
}

void	put_rock(t_game *data, int j, int i)
{
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win,
		data->mlx->images[1],
		j * IMG_SIZE,
		i * IMG_SIZE);
}

void	put_player(t_game *data, int j, int i)
{
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win,
		data->mlx->images[4],
		j * IMG_SIZE,
		i * IMG_SIZE);
}

void	put_exit(t_game *data, int j, int i)
{
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win,
		data->mlx->images[3],
		j * IMG_SIZE,
		i * IMG_SIZE);
}

void	put_empty(t_game *data, int j, int i)
{
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win,
		data->mlx->images[0],
		j * IMG_SIZE,
		i * IMG_SIZE);
}
