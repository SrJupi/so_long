/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:56:13 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/20 11:36:29 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_enemy(t_game *data)
{
	if (add_multiple_images(X, ENEM_FRAMES, "textures_bonus/enem_", data->mlx))
		ft_error(ENOMEM, "mlx images failed", clean_game, data);
}
