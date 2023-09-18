/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:44:12 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/18 10:25:21 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_closed(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= (int)map->col || y >= (int)map->lin)
		return (1);
	if (map->map[y][x] == '1')
		return (0);
	map->map[y][x] = '1';
	if (is_map_closed(map, x, y - 1)
		|| is_map_closed(map, x, y + 1)
		|| is_map_closed(map, x - 1, y)
		|| is_map_closed(map, x + 1, y))
		return (1);
	return (0);
}

void	check_closed(t_game *data)
{
	char	**tmp_map;

	tmp_map = copy_map(data->map);
	if (is_map_closed(data->map,
			data->player.x,
			data->player.y))
	{
		clean_array(tmp_map);
		ft_error(EINVAL, "Map not closed", clean_map, data->map);
	}
	clean_array(data->map->map);
	data->map->map = tmp_map;
}
