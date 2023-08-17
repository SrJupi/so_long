/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:31:38 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/08/14 11:31:40 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player(int x, int y, t_game *data)
{
	data->map->map[data->player.y + y][data->player.x + x] = 'P';
	data->map->map[data->player.y][data->player.x] = '0';
	data->player.x += x;
	data->player.y += y;
	data->player.info += 1;
}

void	update_screen(t_game *data)
{
	data->screen.info = 1;
	if (data->player.x - data->screen.x < -(SCREEN_W / 2 - SCREEN_B))
		data->screen.x--;
	if (data->player.x - data->screen.x > (SCREEN_W / 2 - SCREEN_B))
		data->screen.x++;
	if (data->player.y - data->screen.y < -(SCREEN_H / 2 - SCREEN_B))
		data->screen.y--;
	if (data->player.y - data->screen.y > (SCREEN_H / 2 - SCREEN_B))
		data->screen.y++;
}

void	move_function(int x, int y, t_game *data)
{
	if (!data->map->exit)
		return ;
	if (data->map->map[data->player.y + y][data->player.x + x] == '1')
		return ;
	if (data->map->map[data->player.y + y][data->player.x + x] == 'E'
		&& data->map->collect > 0)
		return ;
	if (data->map->map[data->player.y + y][data->player.x + x] == 'C')
		data->map->collect -= 1;
	if (data->map->map[data->player.y + y][data->player.x + x] == 'E')
		data->map->exit -= 1;
	update_player(x, y, data);
	update_screen(data);
	ft_putstr_fd("\rSteps: ", 1);
	ft_putnbr_fd(data->player.info, 1);
}

int	close_window(t_game *data)
{
	clean_game(data);
	(void)data;
	ft_putchar_fd('\n', 1);
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_keypress(int key, t_game *data)
{
	if (key == 53 || key == 0xff1b)
		close_window(data);
	else if (key == 13 || key == 0x0077)
		move_function(0, -1, data);
	else if (key == 1 || key == 0x0073)
		move_function(0, 1, data);
	else if (key == 0 || key == 0x0061)
		move_function(-1, 0, data);
	else if (key == 2 || key == 0x0064)
		move_function(1, 0, data);
	return (0);
}
