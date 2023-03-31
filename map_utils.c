#include "so_long.h"
#include <stdio.h>

void	check_closed(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i] != VALID_CHAR[1]
			||map->map[map->lin - 1][i] != VALID_CHAR[1])
		{
			clean_map(map);
			ft_perror(EINVAL, "Map not closed");
		}
		i++;
	}
	i = 1;
	while (i < map->lin - 1)
	{
		if (map->map[i][0] != VALID_CHAR[1]
			|| map->map[i][map->col - 1] != VALID_CHAR[1])
		{
			clean_map(map);
			ft_perror(EINVAL, "Map not closed");
		}
		i++;
	}
}

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

int		check_char(char c)
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

void	add_to_count(char c, t_game *data, int i, int j)
{
	if (c == 'C')
		data->map->collect += 1;
	else if (c == 'E')
		data->map->exit += 1;
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

void	create_map(t_game *data, char *arg)
{
	data->map = (t_map *) ft_calloc (1, sizeof(t_map));
	if (data->map == NULL)
		ft_perror(ENOMEM, "map malloc");
	data->map->map = ft_read(ft_open(arg));
	get_map_size(data->map);
	check_closed(data->map);
	check_valid_char(data);
	solve_map(data);
	data->screen.update = 1;
}
