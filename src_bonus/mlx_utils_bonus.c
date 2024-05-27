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

#include "so_long_bonus.h"

void	set_image(t_game *data, int i)
{
	if (i == 0)
		add_back(data);
	else if (i == 1)
		add_wall(data);
	else if (i == C)
		add_collectable(data);
	else if (i == E)
		add_exit(data);
	else if (i == P)
		add_player(data);
	else if (i == X)
		add_enemy(data);
}

void	create_images(t_game *data)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(VALID_CHAR);
	data->mlx->images = (t_sprite *) ft_calloc (size + 1, sizeof(t_sprite));
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
