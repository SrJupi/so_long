/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:09:55 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/18 10:28:41 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_map *map)
{
	size_t	i;
	char	**tmp_map;

	i = 0;
	tmp_map = (char **) ft_calloc((map->lin + 1), sizeof(char *));
	if (tmp_map == NULL)
		ft_error(ENOMEM, "Copy map fail", clean_map, map);
	while (i < map->lin)
	{
		tmp_map[i] = ft_strdup(map->map[i]);
		if (tmp_map[i] == NULL)
		{
			clean_array(tmp_map);
			ft_error(ENOMEM, "Copy map fail", clean_map, map);
		}
		i++;
	}
	return (tmp_map);
}
