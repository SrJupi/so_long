#include "so_long.h"

char	*fake_gnl(int fd)
{
	char	*str;
	char	*tmp;
	int		read_result;

	read_result = 1;
	str = NULL;
	tmp = (char *) malloc (sizeof(char) * 2);
	if (tmp == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (read_result > 0)
	{
		ft_bzero(tmp, 2);
		read_result = read(fd, tmp, 1);
		str = ft_strcat(str, tmp);
		if (str == NULL)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	return (str);
}

/*void	ft_realloc(t_map *map)
{
	void	*new_ptr;

	if (map->map == NULL)
	{
		map->map == (char **) malloc (sizeof(char*) * map->lines + 1);
	}
	new_ptr = malloc (size);
	if (new_ptr == NULL)
	{
		free_map(map);
		return (NULL);
	}
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}*/

/*void	get_map(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		map->map = (char **) ft_realloc (map->map, map->lines * sizeof(char *), (map->lines + 1) * sizeof (char *));
		if (map->map == NULL)
}*/

t_map	ft_read(int fd)
{
	t_map	map_info;
	char	*map_line;

	ft_bzero(&map_info, sizeof(t_map));
	map_line = fake_gnl(fd);
	if (map_line == NULL)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd("map line: \n", 1);
	ft_putstr_fd(map_line, 1);
	map_info.map = ft_split(map_line, '\n');
	return (map_info);
}
