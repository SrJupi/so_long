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

// solve map functions

void	print_map(char **map)
{
	int	i = 0;
	int	j;

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

int		backtrack_map(char **map, t_coord player, t_coord coll_exit)
{
	// ft_putstr_fd("Backtracking... col: ", 1);
	// ft_putnbr_fd(coll_exit.x,1);
	// ft_putstr_fd(" - exit: ",1);
	// ft_putnbr_fd(coll_exit.y,1);

	// ft_putstr_fd(".\n",1);
	// print_map(map);

	if (map[player.y][player.x] == 'C')
	{
		coll_exit.x -= 1;
	}
	else if (map[player.y][player.x] == 'E')
	{
		coll_exit.y -= 1;		
	}
	map[player.y][player.x] = '1';
	if (coll_exit.x == 0 && coll_exit.y == 0)
	{
		ft_putstr_fd("No more collectables and exit!\n\n", 1);
		return (1);
	}
	//go up
	if (map[player.y - 1][player.x] != '1')
	{
		player.y -= 1;
		if (backtrack_map(map, player, coll_exit))
			return (1);
		player.y += 1;
	}

	//go down
	if (map[player.y + 1][player.x] != '1')
	{
		player.y += 1;
		if (backtrack_map(map, player, coll_exit))
			return (1);
		player.y -= 1;
	}

	//go left
	if (map[player.y][player.x - 1] != '1')
	{
		player.x -= 1;
		if (backtrack_map(map, player, coll_exit))
			return (1);
		player.x += 1;
	}
	//go right
	if (map[player.y][player.x + 1] != '1')
	{
		player.x += 1;
		if (backtrack_map(map, player, coll_exit))
			return (1);
		player.x -= 1;
	}
	return (0);
}

void	solve_map(t_game *data)
{
	t_coord	copy_player;
	t_coord	coll_exit;
	// t_coord	map_size;

	ft_putstr_fd("Enter solve\n", 1);
	copy_player.x = data->player.x;
	copy_player.y = data->player.y;
	coll_exit.x = data->map->collect;
	coll_exit.y = data->map->exit;
	// map_size.x = data->map->col;
	// map_size.y = data->map->lin;

	if (backtrack_map(data->map->copy_map, copy_player, coll_exit))
	{
		ft_putstr_fd("Inside return\n", 1);
		clean_array(data->map->copy_map);
		return ;
	}
	else
	{
		ft_putstr_fd("Outside return\n", 1);
		ft_error(EINVAL, "Map not solvable", clean_game, data);
	}
}
