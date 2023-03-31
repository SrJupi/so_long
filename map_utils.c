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

void	add_to_count(char c, t_map *map, int i, int j)
{
	if (c == 'C')
		map->collect += 1;
	else if (c == 'E')
		map->exit += 1;
	else if (c == 'P')
	{
		map->player += 1;
		map->p_x = j;
		map->p_y = i;
	}
}

void	check_quantities(t_map *map)
{
	if (map->player > 1 || map->player < 1)
		ft_error(EINVAL, "Num player", clean_map, map);
	if (map->exit > 1 || map->exit < 1)
		ft_error(EINVAL, "Num exit", clean_map, map);
	if (map->collect < 1)
		ft_error(EINVAL, "Num collect", clean_map, map);
	map->f_x = map->p_x;
	map->f_y = map->p_y;
}

void	check_valid_char(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < map->lin - 1)
	{
		j = 1;
		while (j < map->col - 1)
		{
			if (check_char(map->map[i][j]))
				ft_error(EINVAL, "Char not allowed", clean_map, map);
			add_to_count(map->map[i][j], map, i, j);
			j++;
		}
		i++;
	}
	check_quantities(map);
}

void	create_map(t_map **map, char *arg)
{
	*map = (t_map *) ft_calloc (1, sizeof(t_map));
	if (*map == NULL)
		ft_perror(ENOMEM, "map malloc");
	(*map)->map = ft_read(ft_open(arg));
	get_map_size(*map);
	check_closed(*map);
	check_valid_char(*map);
	solve_map(*map);
	(*map)->update = 1;
}

/*int	main(int argc, char **argv)
{
	int		i;
	t_map	*my_map;

	my_map = NULL;
	i = 0;
	if (argc != 2)
		ft_perror(EINVAL, "Args");
	else
	{
		create_map(&my_map, argv[1]);
		while (my_map->map[i])
		{
			printf("Linha %d: %s\n", i + 1, my_map->map[i]);
			i++;
		}
		clean_map(my_map);
	}
}*/
