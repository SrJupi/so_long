/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:32:21 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/08/14 11:32:22 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar_fd(map[i][j], 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

int	backtrack_map(char **map, int x, int y, int *coll_exit)
{
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'C' || map[y][x] == 'E')
		(*coll_exit) -= 1;
	map[y][x] = '1';
	if ((*coll_exit) == 0)
		return (1);
	if (backtrack_map(map, x, y - 1, coll_exit)
		|| backtrack_map(map, x, y + 1, coll_exit)
		|| backtrack_map(map, x - 1, y, coll_exit)
		|| backtrack_map(map, x + 1, y, coll_exit))
		return (1);
	return (0);
}

void	solve_map(t_game *data)
{
	int	coll_exit;

	coll_exit = data->map->collect + 1;
	if (!backtrack_map(data->map->copy_map, 
			data->player.x,
			data->player.y,
			&coll_exit))
		ft_error(EINVAL, "Map not solvable", clean_game, data);
}
