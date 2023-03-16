#include "so_long.h"

char	*fake_gnl(int fd)
{
	char	*str;
	char	*tmp;
	int		read_result;

	str = NULL;
	tmp = (char *) ft_calloc (1, sizeof(char) * 2);
	if (tmp == NULL)
		ft_perror(ENOMEM, "read");
	read_result = read(fd, tmp, 1);
	if (read_result == 0)
	{
		free(tmp);
		ft_perror(EINVAL, "Empty map");
	}
	while (read_result > 0)
	{
		str = ft_strcat(str, tmp);
		if (str == NULL)
		{
			free(tmp);
			ft_perror(ENOMEM, "ft_strcat");
		}
		read_result = read(fd, tmp, 1);
	}
	free(tmp);
	return (str);
}

char	**ft_read(int fd)
{
	char	*map_line;
	char	**ret_arr;

	map_line = fake_gnl(fd);
	close(fd);
	ret_arr = ft_split(map_line, '\n');
	free(map_line);
	if (ret_arr == NULL)
		ft_perror(ENOMEM, "split");
	return (ret_arr);
}
