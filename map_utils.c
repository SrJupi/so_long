#include "so_long.h"
#include <stdio.h>

void	clean_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map != NULL)
	{
		while (map->map[i] != NULL)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	free(map);
}

void	check_first_last(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i] != VALID_CHAR[1]
			||map->map[map->col - 1][i] != VALID_CHAR[1])
		{
			errno = EINVAL;
			clean_map(map);
			perror("Map not closed");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_other_lines(t_map *map)
{
	(void)map;
}

void	check_valid_map(t_map *map)
{
	check_first_last(map);
	check_other_lines(map);
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
			errno = EINVAL;
			clean_map(map);
			perror("Map is not rectangle");
			exit(EXIT_FAILURE);
		}
		map->lin += 1;
		i++;
	}
}

void	check_map(t_map *map)
{
	get_map_size(map);
	check_valid_map(map);
}

void	create_map(t_map **map, char *arg)
{
	*map = (t_map *) ft_calloc (1, sizeof(t_map));
	if (*map == NULL)
	{
		errno = ENOMEM;
		perror ("map malloc");
		exit(EXIT_FAILURE);
	}
	(*map)->map = ft_read(ft_open(arg));
	check_map(*map);
}

int	main(int argc, char **argv)
{
	int		i;
	t_map	*my_map;

	my_map = NULL;
	i = 0;
	if (argc != 2)
		printf("Oh oh! Not enough args!\n");
	else
	{
		create_map(&my_map, argv[1]);
		while (my_map->map[i])
		{
			printf("Linha %d: %s\n", i + 1, my_map->map[i]);
			i++;
		}
	}
}
