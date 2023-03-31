#include "so_long.h"

//check leaks
void	clean_map(void *map)
{
	int		i;
	t_map	*cast;

	cast = (t_map *)map;
	i = 0;
	if (cast->map != NULL)
	{
		while (cast->map[i] != NULL)
		{
			free(cast->map[i]);
			i++;
		}
		free(cast->map);
	}
	free(cast);
}

void	clean_images(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->images[i] != NULL)
	{
		//clean image function from mlx
		mlx_destroy_image(mlx->mlx, mlx->images[i]);
		i++;
	}
	free(mlx->images);
}

void	clean_mlx(void *mlx)
{
	t_mlx	*cast;

	cast = (t_mlx *)mlx;
	if (cast->images != NULL)
		clean_images(cast);
	if (cast->mlx_win != NULL)
		mlx_destroy_window(cast->mlx, cast->mlx_win);
	if (cast->mlx != NULL)
		mlx_destroy_display(cast->mlx);
	free(cast);
}

void	clean_game(void *data)
{
	t_game	*cast;

	cast = (t_game *)data;
	clean_map(cast->map);
	clean_mlx(cast->mlx);
}
