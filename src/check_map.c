/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:24:24 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/08/15 10:24:27 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_to_count(char c, t_game *data, int i, int j)
{
	if (c == 'C')
		data->map->collect += 1;
	else if (c == 'E')
	{
		data->map->exit += 1;
		data->exit.x = j;
		data->exit.y = i;
		data->exit.info = 0;
	}
	else if (c == 'P')
	{
		data->map->player += 1;
		data->player.x = j;
		data->player.y = i;
	}
}

void	check_quantities(t_game *data)
{
	if (data->map->player > 1 || data->map->player < 1)
		ft_error(EINVAL, "Num player", clean_map, data->map);
	if (data->map->exit > 1 || data->map->exit < 1)
		ft_error(EINVAL, "Num exit", clean_map, data->map);
	if (data->map->collect < 1)
		ft_error(EINVAL, "Num collect", clean_map, data->map);
	data->screen.x = data->player.x;
	data->screen.y = data->player.y;
}

int	check_char(char c)
{
	int	i;

	i = 0;
	while (VALID_CHAR[i])
	{
		if (c == VALID_CHAR[i])
			return (0);
		i++;
	}
	return (1);
}

void	check_valid_char(t_game *data)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < data->map->lin - 1)
	{
		j = 1;
		while (j < data->map->col - 1)
		{
			if (check_char(data->map->map[i][j]))
				ft_error(EINVAL, "Char not allowed", clean_map, data->map);
			add_to_count(data->map->map[i][j], data, i, j);
			j++;
		}
		i++;
	}
	check_quantities(data);
}
