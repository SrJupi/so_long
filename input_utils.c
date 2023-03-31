#include "so_long.h"

void	move_function(int x, int y, t_game *data)
{
	if (data->map->exit == 0)
		return ;
	//check move pos
	if (data->map->map[data->player.y + y][data->player.x + x] == '1')
		return ;
	if (data->map->map[data->player.y + y][data->player.x + x] == 'E'
		&& data->map->collect > 0)
		return ;
	if (data->map->map[data->player.y + y][data->player.x + x] == 'C')
		data->map->collect -= 1;
	if (data->map->map[data->player.y + y][data->player.x + x] == 'E')
		data->map->exit -= 1;	
	//move player if possible
	data->map->map[data->player.y + y][data->player.x + x] = 'P';
	data->map->map[data->player.y][data->player.x] = '0';
	data->player.x += x;
	data->player.y += y;
	data->player.steps += 1;
	ft_putstr_fd("\rCollectables: ", 1);
	ft_putnbr_fd(data->map->collect, 1);
	ft_putstr_fd("- Steps: ", 1);
	ft_putnbr_fd(data->player.steps, 1);
	data->screen.update = 1;
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
		move_function(0, -1, data);
	else if (key == XK_s)
		move_function(0, 1, data);
	else if (key == XK_a)
		move_function(-1, 0, data);
	else if (key == XK_d)
		move_function(1, 0, data);
	return (0);
}
