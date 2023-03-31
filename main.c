#include "so_long.h"

int	PIXELS = 32;

void	move_function(int x, int y, t_map *map)
{
	int	p_x;
	int	p_y;

	p_x = map->p_x;
	p_y = map->p_y;
	//check move pos
	if (map->map[p_y + y][p_x + x] == '1')
		return ;
	if (map->map[p_y + y][p_x + x] == 'E'
		&& map->collect > 0)
		return ;
	if (map->map[p_y + y][p_x + x] == 'C')
		map->collect -= 1;
	if (map->map[p_y + y][p_x + x] == 'E')
		map->exit -= 1;	
	//move player if possible
	map->map[p_y + y][p_x + x] = 'P';
	map->map[p_y][p_x] = '0';
	map->p_x = p_x + x;
	map->p_y = p_y + y;
	map->update = 1;
}

int	close_window(t_game *data)
{
	clean_game(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_keypress(int key, t_game *data)
{
	if (key == XK_Escape)
		close_window(data);
	else if (key == XK_w)
		move_function(0, -1, data->map);
	else if (key == XK_s)
		move_function(0, 1, data->map);
	else if (key == XK_a)
		move_function(-1, 0, data->map);
	else if (key == XK_d)
		move_function(1, 0, data->map);
	return (0);
}

/*int	handle_mouse(int action, void *data)
{
	(void)data;
	printf("Mouse %i pressed!\n", action);
	return (0);
}

int	handle_mouse_move(int x, int y, void *data)
{
	(void)data;
	printf("Mouse is at:\nX= %i\nY= %i\n", x, y);
	return (0);
}
*/



/*int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}*/

/*int	draw_win(t_mlx *data)
{
	int	i = 0;
	int	j;
	
	while(data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->empty, j * PIXELS, i * PIXELS);
			j++;
		}
		i++;
	}
	return (0);
}
*/
void	aux_draw(t_map *map, t_mlx *data)
{
	static int	counter;
	int		i = 0;
	int		j;
	char	c;

	
	ft_putstr_fd("aux draw map - time: ", 1);
	ft_putnbr_fd(counter, 1);
	ft_putchar_fd('\n', 1);
	counter++;
	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			c = map->map[i][j];
			if (c == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[4], j * PIXELS, i * PIXELS);
			if (c == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[1], j * PIXELS, i * PIXELS);
			if (c == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[0], j * PIXELS, i * PIXELS);
			if (c == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[2], j * PIXELS, i * PIXELS);
			if (c == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[3], j * PIXELS, i * PIXELS);
			j++;
		}
		i++;
	}
	map->update = 0;
}

int	draw_map(t_game *data)
{
	if (data->map->update)
		aux_draw(data->map, data->mlx);
//	if (data->map->exit == 0)
//		return (draw_win(data));
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	data;
//	t_data	img;
//	int		pix = 32;

	//bzero(&data, sizeof(data));
	if (argc != 2)
		ft_perror(EINVAL, "./so_long [MAP.ber]");
	ft_putstr_fd("create map\n", 1);
	create_map(&data.map, argv[1]);
	ft_putstr_fd("create mlx struct\n", 1);
	create_mlx(&data);
//	draw_map(&data);
	ft_putstr_fd("player position: x: ", 1);
	ft_putnbr_fd(data.map->p_x, 1);
	ft_putstr_fd(" - y: ", 1);
	ft_putnbr_fd(data.map->p_y, 1);
	ft_putstr_fd("\nfocus position: x: ", 1);
	ft_putnbr_fd(data.map->f_x, 1);
	ft_putstr_fd(" - y: ", 1);
	ft_putnbr_fd(data.map->f_y, 1);
	ft_putstr_fd("\ninit hooks\n", 1);
	mlx_key_hook(data.mlx->mlx_win, &handle_keypress, &data);
//	mlx_mouse_hook(data.mlx_win, &handle_mouse, NULL);
	mlx_loop_hook(data.mlx->mlx, &draw_map, &data);
//	mlx_hook(data.mlx_win, 6, 1L<<6, handle_mouse_move, NULL);
	mlx_hook(data.mlx->mlx_win, 17, 1L<<17, close_window, &data);
	mlx_loop(data.mlx->mlx);
	return (0);
}
