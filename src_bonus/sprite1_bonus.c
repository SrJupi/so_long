/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:56:13 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/20 11:36:19 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_back(t_game *data)
{
	if (add_multiple_images(0, BACK_FRAMES, "textures_bonus/back_", data->mlx))
		ft_error(ENOMEM, "mlx images failed", clean_game, data);
}

void	add_wall(t_game *data)
{
	if (add_multiple_images(1, WALL_FRAMES, "textures_bonus/wall_", data->mlx))
		ft_error(ENOMEM, "mlx images failed", clean_game, data);
}

void	add_collectable(t_game *data)
{
	if (add_multiple_images(C, COLL_FRAMES, "textures_bonus/coll_", data->mlx))
		ft_error(ENOMEM, "mlx images failed", clean_game, data);
}

void	add_exit(t_game *data)
{
	if (add_multiple_images(E, EXIT_FRAMES, "textures_bonus/exit_", data->mlx))
		ft_error(ENOMEM, "mlx images failed", clean_game, data);
}

void	add_player(t_game *data)
{
	if (add_multiple_images(P, PLAY_FRAMES, "textures_bonus/play_", data->mlx))
		ft_error(ENOMEM, "mlx images failed", clean_game, data);
}
