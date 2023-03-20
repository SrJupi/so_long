#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include "so_long.h"

int	PIXELS = 32;

typedef struct	t_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collect;
	void	*back;
	void	*empty;
	t_map	*map;
} t_mlx;

void	move_function(int x, int y, t_mlx *data)
{
	int	p_x;
	int	p_y;

	p_x = data->map->p_x;
	p_y = data->map->p_y;
	//check move pos
	if (data->map->map[p_y + y][p_x + x] == '1')
		return ;
	if (data->map->map[p_y + y][p_x + x] == 'E'
		&& data->map->collect > 0)
		return ;
	if (data->map->map[p_y + y][p_x + x] == 'C')
		data->map->collect -= 1;
	if (data->map->map[p_y + y][p_x + x] == 'E')
		data->map->exit -= 1;	
	//move player if possible
	data->map->map[p_y + y][p_x + x] = 'P';
	data->map->map[p_y][p_x] = '0';
	data->map->p_x = p_x + x;
	data->map->p_y = p_y +y;
}

int	close_window(t_mlx *data)
{
	clean_map(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	printf("Window gone!\n");
	mlx_destroy_display(data->mlx);
	printf("Display gone!\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_keypress(int key, t_mlx *data)
{
	if (key == XK_Escape)
		close_window(data);
	else if (key == XK_w)
		move_function(0, -1, data);
	else if (key == XK_s)
		move_function(0, 1, data);
	else if (key == XK_a)
		move_function(-1, 0, data);
	else if (key == XK_d)
		move_function(1, 0, data);
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

int	draw_win(t_mlx *data)
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

int	draw_map(t_mlx *data)
{
	int	i = 0;
	int	j;
	char	c;
	
	if (data->map->exit == 0)
		return (draw_win(data));
	while(data->map->map[i])
	{
		j = 0;
		while(data->map->map[i][j])
		{
			c = data->map->map[i][j];
			if (c == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, j * PIXELS, i * PIXELS);
			if (c == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, j * PIXELS, i * PIXELS);
			if (c == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->back, j * PIXELS, i * PIXELS);
			if (c == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->collect, j * PIXELS, i * PIXELS);
			if (c == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit, j * PIXELS, i * PIXELS);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	data;
//	t_data	img;
	int		pix = 32;

	//bzero(&data, sizeof(data));
	if (argc != 2)
		ft_perror(EINVAL, "Args");
	ft_putstr_fd("init map\n", 1);
	create_map(&data.map, argv[1]);
	ft_putstr_fd("init mlx\n", 1);
	data.mlx = mlx_init();
	ft_putstr_fd("create win\n", 1);
	data.mlx_win = mlx_new_window(data.mlx, (int)data.map->col * PIXELS, (int)data.map->lin * PIXELS, "So LoNg!");
	ft_putstr_fd("create images\n", 1);
	data.wall = mlx_xpm_file_to_image(data.mlx, "img/wall_32.xpm", &pix, &pix);
	data.player = mlx_xpm_file_to_image(data.mlx, "img/player_32.xpm", &pix, &pix);
	data.exit = mlx_xpm_file_to_image(data.mlx, "img/exit_32.xpm", &pix, &pix);
	data.collect = mlx_xpm_file_to_image(data.mlx, "img/collectable_32.xpm", &pix, &pix);
	data.back = mlx_xpm_file_to_image(data.mlx, "img/background_32.xpm", &pix, &pix);
	data.empty = mlx_xpm_file_to_image(data.mlx, "img/gold_32.xpm", &pix, &pix);
	ft_putstr_fd("draw map\n", 1);
//	draw_map(&data);
	ft_putstr_fd("player position: x: ", 1);
	ft_putnbr_fd(data.map->p_x, 1);
	ft_putstr_fd(" - y: ", 1);
	ft_putnbr_fd(data.map->p_y, 1);
	ft_putstr_fd("\ninit hooks\n", 1);
	mlx_key_hook(data.mlx_win, &handle_keypress, &data);
//	mlx_mouse_hook(data.mlx_win, &handle_mouse, NULL);
	mlx_loop_hook(data.mlx, &draw_map, &data);
//	mlx_hook(data.mlx_win, 6, 1L<<6, handle_mouse_move, NULL);
	mlx_hook(data.mlx_win, 17, 1L<<17, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
