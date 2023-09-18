/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:31:24 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/08/30 18:08:21 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

int	draw_map(t_game *data)
{
	if (data->screen.info)
	{
		display_screen(data);
		data->screen.info = 0;
		if (!data->map->exit)
			draw_win(data);
	}
	return (0);
}
