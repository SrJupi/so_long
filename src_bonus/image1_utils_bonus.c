/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image1_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:21:51 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/19 19:55:54 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_collectable(t_game *data, int j, int i)
{
	int	pos;

	pos = data->cycles % data->mlx->images[C].size;
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win,
		data->mlx->images[C].sprites[pos],
		j * IMG_SIZE,
		i * IMG_SIZE);
}

void	put_rock(t_game *data, int j, int i)
{
	int	pos;

	pos = data->cycles % data->mlx->images[1].size;
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win,
		data->mlx->images[1].sprites[pos],
		j * IMG_SIZE,
		i * IMG_SIZE);
}

void	put_player(t_game *data, int j, int i)
{
	int	pos;

	pos = data->cycles % data->mlx->images[P].size;
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win,
		data->mlx->images[P].sprites[pos],
		j * IMG_SIZE,
		i * IMG_SIZE);
}

void	put_exit(t_game *data, int j, int i)
{
	int	pos;

	pos = data->cycles % data->mlx->images[E].size;
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win,
		data->mlx->images[E].sprites[pos],
		j * IMG_SIZE,
		i * IMG_SIZE);
}

void	put_empty(t_game *data, int j, int i)
{
	int	pos;

	pos = data->cycles % data->mlx->images[0].size;
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win,
		data->mlx->images[0].sprites[pos],
		j * IMG_SIZE,
		i * IMG_SIZE);
}
