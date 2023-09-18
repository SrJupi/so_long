/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:32:02 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/08/30 18:16:47 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		img = mlx_xpm_file_to_image(data->mlx->mlx, "textures/back.xpm", w, h);
	else if (i == 1)
		img = mlx_xpm_file_to_image(data->mlx->mlx, "textures/wall.xpm", w, h);
	else if (i == C)
		img = mlx_xpm_file_to_image(data->mlx->mlx, "textures/coll.xpm", w, h);
	else if (i == E)
		img = mlx_xpm_file_to_image(data->mlx->mlx, "textures/exit.xpm", w, h);
	else if (i == P)
		img = mlx_xpm_file_to_image(data->mlx->mlx, "textures/play.xpm", w, h);
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
	data->mlx = (t_mlx *) ft_calloc (1, sizeof(t_mlx));
	if (data->mlx == NULL)
		ft_error(ENOMEM, "mlx malloc", clean_map, data->map);
	data->mlx->mlx = mlx_init();
	if (data->mlx->mlx == NULL)
		ft_error(ENOMEM, "mlx failed", clean_map, data->map);
	data->mlx->mlx_win = mlx_new_window(data->mlx->mlx, \
	SCREEN_W * IMG_SIZE, SCREEN_H * IMG_SIZE, "So LoNg!");
	if (data->mlx->mlx_win == NULL)
		ft_error(ENOMEM, "mlx win failed", clean_game, data);
	create_images(data);
}
