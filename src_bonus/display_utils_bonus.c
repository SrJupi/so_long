/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:31:24 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/19 19:55:14 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	draw_win(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_H)
	{
		j = 0;
		while (j < SCREEN_W)
		{
			if ((i + j) % 2 == 0)
				put_collectable(data, j, i);
			else
				put_rock(data, j, i);
			j++;
		}
		i++;
	}
	return (0);
}

void	draw_lose(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_H)
	{
		j = 0;
		while (j < SCREEN_W)
		{
			put_rock(data, j, i);
			j++;
		}
		i++;
	}
}

void	aux_scroll(t_game *data, int i, int j)
{
	int		x;
	int		y;
	char	c;

	x = data->screen.x - SCREEN_W / 2 + j;
	y = data->screen.y - SCREEN_H / 2 + i;
	if (x < 0 || y < 0 || x >= (int)data->map->col || y >= (int)data->map->lin)
		c = '0';
	else
		c = data->map->map[y][x];
	if (c == 'P')
		put_player(data, j, i);
	if (c == '1')
		put_rock(data, j, i);
	if (c == '0')
		put_empty(data, j, i);
	if (c == 'C')
		put_collectable(data, j, i);
	if (c == 'E')
		put_exit(data, j, i);
	if (c == 'X')
		put_enemy(data, j, i);
}

void	display_screen(t_game *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < SCREEN_H)
	{
		j = 0;
		while (j < SCREEN_W)
		{
			aux_scroll(data, i, j);
			j++;
		}
		i++;
	}
	//Need refactor and is ugly
	char *steps = ft_strjoin("Steps: ", ft_itoa(data->steps));
	mlx_string_put(data->mlx->mlx, data->mlx->mlx_win,  data->mlx->img_w / 2, (SCREEN_H * data->mlx->img_h) - data->mlx->img_h,  0xFFFFFF, steps);
	char *lives = ft_strjoin("Lives: ", ft_itoa(data->player.info));
	mlx_string_put(data->mlx->mlx, data->mlx->mlx_win,  (SCREEN_W * data->mlx->img_w) - data->mlx->img_w * 4, (SCREEN_H * data->mlx->img_h) - data->mlx->img_h,  0xFFFFFF, lives);

	data->last_update = get_milliseconds();
}

void	update_sprites(t_game *data)
{
	if (get_milliseconds() - data->last_update > FPS_RATE)
	{
		data->cycles++;
		data->cycles %= 280;
		data->screen.info = 1;
	}
}

int	draw_map(t_game *data)
{
	if (!data->is_game_over)
	{
		if (data->screen.info)
		{
			display_screen(data);
			data->screen.info = 0;
			if (!data->map->exit)
			{
				draw_win(data);
				data->is_game_over = 1;
			}
		}
		else
		{
			update_sprites(data);
		}
	}
	return (0);
}
