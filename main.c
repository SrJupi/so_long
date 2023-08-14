/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:31:45 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/08/14 11:31:47 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_structs(t_game *data, char *argv)
{
	data->player.steps = 0;
	create_map(data, argv);
	create_mlx(data);
}

void	do_game_magic(t_game *data)
{
	mlx_hook(data->mlx->mlx_win, 2, 1L<<0, &handle_keypress, data);
	mlx_loop_hook(data->mlx->mlx, &draw_map, data);
	mlx_hook(data->mlx->mlx_win, 17, 1L<<17, close_window, data);
	mlx_loop(data->mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		ft_perror(EINVAL, "./so_long [MAP.ber]");
	init_structs(&data, argv[1]);
	do_game_magic(&data);
	return (0);
}
