#include "so_long.h"

void	ft_perror(int err, char *msg)
{
	if (err)
		errno = err;
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_error(int err, char *msg, void (*clean_func)(void *), void *data)
{
	if (clean_func != NULL && data != NULL)
		clean_func(data);
	ft_perror(err, msg);
}
