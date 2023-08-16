/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:31:53 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/08/14 11:31:57 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// #include <stdio.h>

void	get_map_size(t_map *map)
{
	int	i;

	i = 0;
	map->col = ft_strlen(map->map[0]);
	while (map->map[i] != NULL)
	{
		if (map->col != ft_strlen(map->map[i]))
		{
			clean_map(map);
			ft_perror(EINVAL, "Map is not rectangle");
		}
		map->lin += 1;
		i++;
	}
}

void	create_map(t_game *data, char *arg)
{
	data->map = (t_map *) ft_calloc (1, sizeof(t_map));
	if (data->map == NULL)
		ft_perror(ENOMEM, "map malloc");
	data->map->map = ft_read(ft_open(arg));
	data->map->copy_map = ft_read(ft_open(arg));
	get_map_size(data->map);
	check_closed(data->map);
	check_valid_char(data);
	solve_map(data);
	data->screen.info = 1;
}
