/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:31:24 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/08/14 11:31:26 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	draw_win(t_mlx *data)
{
	int	i = 0;
	int	j;
	
	while(data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->empty, j * IMG_SIZE, i * IMG_SIZE);
			j++;
		}
		i++;
	}
	return (0);
}
*/

void	aux_scroll(t_game *data)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	c;

	i = 0;
	while (i < SCREEN_H)
	{
		j = 0;
		while (j < SCREEN_W)
		{
			x = data->screen.x - SCREEN_W / 2 + j;
			y = data->screen.y - SCREEN_H / 2 + i;
			if (x < 0 || y < 0 || x >= (int)data->map->col || y >= (int)data->map->lin)
				c = '0';
			else
				c = data->map->map[y][x];
			if (c == 'P')
				mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->images[4], j * IMG_SIZE, i * IMG_SIZE);
			if (c == '1')
				mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->images[1], j * IMG_SIZE, i * IMG_SIZE);
			if (c == '0')
				mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->images[0], j * IMG_SIZE, i * IMG_SIZE);
			if (c == 'C')
				mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->images[2], j * IMG_SIZE, i * IMG_SIZE);
			if (c == 'E')
				mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->images[3], j * IMG_SIZE, i * IMG_SIZE);
			j++;
		}
		i++;
	}
}

// void	aux_draw(t_map *map, t_mlx *data)
// {
// 	int		i;
// 	int		j;
// 	char	c;

// 	i = 0;
// 	while (map->map[i])
// 	{
// 		j = 0;
// 		while (map->map[i][j])
// 		{
// 			c = map->map[i][j];
// 			if (c == 'P')
// 				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[4], j * IMG_SIZE, i * IMG_SIZE);
// 			if (c == '1')
// 				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[1], j * IMG_SIZE, i * IMG_SIZE);
// 			if (c == '0')
// 				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[0], j * IMG_SIZE, i * IMG_SIZE);
// 			if (c == 'C')
// 				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[2], j * IMG_SIZE, i * IMG_SIZE);
// 			if (c == 'E')
// 				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[3], j * IMG_SIZE, i * IMG_SIZE);
// 			j++;
// 		}
// 		i++;
// 	}
// }

int	draw_map(t_game *data)
{
	if (data->screen.info)
	{
		aux_scroll(data);
		data->screen.info = 0;
	}
//	if (data->map->exit == 0)
//		return (draw_win(data));
	return (0);
}
