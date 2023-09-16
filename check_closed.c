/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:44:12 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 18:45:33 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_closed(t_map *map, int x, int y)
{
	int	max_x;
	int	max_y;

	max_x = (int)map->col;
	max_x--;
	max_y = (int)map->lin;
	max_y--;
	ft_putstr_fd("is closed\n", 1);
	ft_putnbr_fd(x, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(max_x, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(x > max_x, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(max_y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(y > max_y, 1);
	ft_putchar_fd('\n', 1);

	if (x < 0)
	{
		ft_putstr_fd("inside x\n", 1);
		return (1);
	}
	if (y < 0)
	{
		ft_putstr_fd("inside y\n", 1);
		return (1);

	}	
	if (x > max_x)
	{
		ft_putstr_fd("inside x\n", 1);
		return (1);
	}
	if (y > max_y)
	{
		ft_putstr_fd("inside y\n", 1);
		return (1);
	}

	if (map->map[y][x] == '1')
		return (0);


	map->map[y][x] = '1';
	if (is_map_closed(map, x, y - 1)
		|| is_map_closed(map, x, y + 1)
		|| is_map_closed(map, x - 1, y)
		|| is_map_closed(map, x + 1, y))
		ft_putstr_fd("inside return\n", 1);
		return (1);
	return (0);
}

void	check_closed(t_game *data)
{
	if (is_map_closed(data->map,
			data->player.x,
			data->player.y))
		ft_error(EINVAL, "Map not closed", clean_game, data);
	clean_array(data->map->map);
}
