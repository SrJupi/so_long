#include "so_long.h"

void	init_structs(t_game *data, char *argv)
{
	ft_putstr_fd("create map\n", 1);
	data->player.steps = 0;
	create_map(data, argv);
	ft_putstr_fd("create mlx struct\n", 1);
	create_mlx(data);
}

void	do_game_magic(t_game *data)
{
	mlx_hook(data->mlx->mlx_win, KeyPress, KeyPressMask, &handle_keypress, data);
//	mlx_key_hook(data->mlx->mlx_win, &handle_keypress, data);
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
	ft_putstr_fd("\ninit hooks\n", 1);
	do_game_magic(&data);
	return (0);
}
