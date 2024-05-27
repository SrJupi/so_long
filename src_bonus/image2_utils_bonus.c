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

void	put_enemy(t_game *data, int j, int i)
{
	int	pos;

	pos = data->cycles % data->mlx->images[X].size;
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win,
		data->mlx->images[X].sprites[pos],
		j * IMG_SIZE,
		i * IMG_SIZE);
}
