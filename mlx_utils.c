#include "so_long.h"

void	set_image(t_game *data, int i)
{
	void	*img;
	int		*w;
	int		*h;

	img = NULL;
	w = &data->mlx->img_w;
	h = &data->mlx->img_h;
	if (i == 0)
		img = mlx_xpm_file_to_image(data->mlx->mlx, "img/back.xpm", w, h);
	else if (i == 1)
		img = mlx_xpm_file_to_image(data->mlx->mlx, "img/wall.xpm", w, h);
	else if (i == C)
		img = mlx_xpm_file_to_image(data->mlx->mlx, "img/coll.xpm", w, h);
	else if (i == E)
		img = mlx_xpm_file_to_image(data->mlx->mlx, "img/exit.xpm", w, h);
	else if (i == P)
		img = mlx_xpm_file_to_image(data->mlx->mlx, "img/play.xpm", w, h);
	if (img == NULL)
		ft_error(ENOMEM, "mlx images failed", clean_game, data);
	data->mlx->images[i] = img;
}

void	create_images(t_game *data)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(VALID_CHAR);
	data->mlx->images = (void **) ft_calloc (size + 1, sizeof(void *));
	if (data->mlx->images == NULL)
		ft_error(ENOMEM, "images malloc", clean_game, data);
	i = 0;
	while (i < size)
	{
		set_image(data, i);
		i++;
	}
}

void	create_mlx(t_game *data)
{
	ft_putstr_fd("malloc mlx\n", 1);
	data->mlx = (t_mlx *) ft_calloc (1, sizeof(t_mlx));
	if (data->mlx == NULL)
		ft_error(ENOMEM, "mlx malloc", clean_map, data->map);
	ft_putstr_fd("init mlx\n", 1);
	data->mlx->mlx = mlx_init();
	if (data->mlx->mlx == NULL)
		ft_error(ENOMEM, "mlx failed", clean_map, data->map);
	ft_putstr_fd("create win\n", 1);
	data->mlx->mlx_win = mlx_new_window(data->mlx->mlx, \
	data->map->col * IMG_SIZE, data->map->lin * IMG_SIZE, "So LoNg!");
	if (data->mlx->mlx_win == NULL)
		ft_error(ENOMEM, "mlx win failed", clean_game, data);
	ft_putstr_fd("create images\n", 1);
	create_images(data);
}
