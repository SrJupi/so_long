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

	if (s1 == NULL)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	if (s2 == NULL)
		len2 = 0;
	else
		len2 = ft_strlen(s2);
	filepath = (char *) malloc (len1 + len2 + 1);
	if (filepath == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(filepath, s1, len1);
	ft_memcpy(filepath + len1, s2, len2 + 1);
	return (filepath);
}

int	check_extension(char *filename)
{
	if (ft_strcmp(EXTENSION, ft_strrchr(filename, '.')))
	{
		errno = EINVAL;
		return (1);
	}
	return (0);
}

int	ft_open(char *filename)
{
	char	*filepath;
	int		fd;

	if (check_extension(filename))
	{
		perror(".ber extension");
		exit(EXIT_FAILURE);
	}
	filepath = ft_strcat(MAP_FOLDER, filename);
	if (filepath == NULL)
	{
		perror("strcat");
		exit(EXIT_FAILURE);
	}
	fd = open(filepath, O_RDONLY);
	free(filepath);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
