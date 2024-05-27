/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:31:38 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/19 14:53:46 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_player(int x, int y, t_game *data)
{
	int	was_exit;

	was_exit = data->map->map[data->player.y + y][data->player.x + x] == 'E';
	data->map->map[data->player.y + y][data->player.x + x] = 'P';
	if (data->exit.info)
	{
		data->map->map[data->player.y][data->player.x] = 'E';
		data->exit.info = 0;
	}
	else
		data->map->map[data->player.y][data->player.x] = '0';
	if (was_exit)
		data->exit.info = 1;
	data->player.x += x;
	data->player.y += y;
	data->steps += 1;
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

void	lose_live(t_game *data)
{
	data->player.info -= 1;
	if (data->player.info < 1)
	{
		data->is_game_over = 1;
		draw_lose(data);
	}
}

void	move_function(int x, int y, t_game *data)
{
	if (!data->map->exit)
		return ;
	if (data->map->map[data->player.y + y][data->player.x + x] == '1')
		return ;
	if (data->map->map[data->player.y + y][data->player.x + x] == 'X')
		return (lose_live(data));
	if (data->map->map[data->player.y + y][data->player.x + x] == 'C')
		data->map->collect -= 1;
	if (data->map->map[data->player.y + y][data->player.x + x] == 'E'
		&& data->map->collect == 0)
		data->map->exit -= 1;
	update_player(x, y, data);
	update_screen(data);
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(data->steps, 1);
	ft_putstr_fd(" - : ", 1);
	ft_putstr_fd("Lives: ", 1);
	ft_putnbr_fd(data->player.info, 1);
	ft_putstr_fd("\n", 1);
}

int	close_window(t_game *data)
{
	clean_game(data);
	ft_putchar_fd('\n', 1);
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_keypress(int key, t_game *data)
{
	if (key == 53 || key == 0xff1b)
		close_window(data);
	if (!data->is_game_over)
	{
		if (key == 13 || key == 0x0077)
			move_function(0, -1, data);
		if (key == 1 || key == 0x0073)
			move_function(0, 1, data);
		if (key == 0 || key == 0x0061)
			move_function(-1, 0, data);
		if (key == 2 || key == 0x0064)
			move_function(1, 0, data);
	}
	return (0);
}
