#include "so_long.h"

/*int	draw_win(t_mlx *data)
{
	int	i = 0;
	int	j;
	
	while(data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->empty, j * IMG_SIZE, i * IMG_SIZE);
			j++;
		}
		i++;
	}
	return (0);
}
*/

// NOT WORKING =(
void	aux_scroll(t_game *data)
{
	char	c;
	int		x;
	int		y;

	y = data->screen.y - 4;
	while(y <= data->screen.y + 4)
	{
		x = data->screen.x - 7;
		while(x <= data->screen.x + 7)
		{
			if (x < 0 || x >= (int)data->map->col || y < 0 || y >= (int)data->map->lin)
				c = '1';
			else
				c = data->map->map[y][x];
			if (c == 'P')
				mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->images[4], x * IMG_SIZE, y * IMG_SIZE);
			if (c == '1')
				mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->images[1], x * IMG_SIZE, y * IMG_SIZE);
			if (c == '0')
				mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->images[0], x * IMG_SIZE, y * IMG_SIZE);
			if (c == 'C')
				mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->images[2], x * IMG_SIZE, y * IMG_SIZE);
			if (c == 'E')
				mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->images[3], x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
	}
}

void	aux_draw(t_map *map, t_mlx *data)
{
	int		i = 0;
	int		j;
	char	c;

	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			c = map->map[i][j];
			if (c == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[4], j * IMG_SIZE, i * IMG_SIZE);
			if (c == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[1], j * IMG_SIZE, i * IMG_SIZE);
			if (c == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[0], j * IMG_SIZE, i * IMG_SIZE);
			if (c == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[2], j * IMG_SIZE, i * IMG_SIZE);
			if (c == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[3], j * IMG_SIZE, i * IMG_SIZE);
			j++;
		}
		i++;
	}
}

int	draw_map(t_game *data)
{
	if (data->screen.update)
	{
		
		ft_putstr_fd("player position: x: ", 1);
		ft_putnbr_fd(data->player.x, 1);
		ft_putstr_fd(" - y: ", 1);
		ft_putnbr_fd(data->player.y, 1);
		ft_putstr_fd("\nfocus position: x: ", 1);
		ft_putnbr_fd(data->screen.x, 1);
		ft_putstr_fd(" - y: ", 1);
		ft_putnbr_fd(data->screen.y, 1);
		ft_putchar_fd('\n', 1);
		aux_draw(data->map, data->mlx);
		//aux_scroll(data);
		
		data->screen.update = 0;
	}
//	if (data->map->exit == 0)
//		return (draw_win(data));
	return (0);
}
