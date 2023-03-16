#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL || s2 == NULL)
		return (1);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strcat(char *s1, char *s2)
{
	char	*filepath;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!len1 && !len2)
		return (NULL);
	filepath = (char *) ft_calloc (1, len1 + len2 + 1);
	if (filepath == NULL)
		return (NULL);
	ft_memcpy(filepath, s1, len1);
	ft_memcpy(filepath + len1, s2, len2);
	return (filepath);
}

void	check_extension(char *filename)
{
	if (ft_strcmp(EXTENSION, ft_strrchr(filename, '.')))
		ft_perror(EINVAL, ".ber extension");
}

int	ft_open(char *filename)
{
	char	*filepath;
	int		fd;

	check_extension(filename);
	filepath = ft_strcat(MAP_FOLDER, filename);
	if (filepath == NULL)
		ft_perror(ENOMEM, "ft_strcat");
	fd = open(filepath, O_RDONLY);
	free(filepath);
	if (fd == -1)
		ft_perror(0, "open");
	return (fd);
}
