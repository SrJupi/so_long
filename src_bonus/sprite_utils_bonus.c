/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:56:13 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/20 11:49:58 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_filepath(char *og_path, int i)
{
	char	*tmp;
	char	*i_itoa;

	tmp = NULL;
	i_itoa = ft_itoa(i);
	if (i_itoa != NULL)
	{
		tmp = ft_strcat(og_path, i_itoa, 0);
		free(i_itoa);
		if (tmp == NULL)
			return (NULL);
		tmp = ft_strcat(tmp, ".xpm", 1);
	}
	return (tmp);
}

int	add_multiple_images(int sp, int num, char *og_path, t_mlx *mlx)
{
	void	*img;
	int		i;
	char	*filepath;

	i = 0;
	mlx->images[sp].size = num;
	mlx->images[sp].sprites = (void **) ft_calloc (num + 1, sizeof(void *));
	if (mlx->images[sp].sprites == NULL)
		return (1);
	while (i < num)
	{
		filepath = get_filepath(og_path, i);
		if (filepath == NULL)
			return (1);
		img = mlx_xpm_file_to_image (mlx->mlx, filepath,
				&mlx->img_w, &mlx->img_h);
		free(filepath);
		if (img == NULL)
			return (1);
		mlx->images[sp].sprites[i] = img;
		i++;
	}
	return (0);
}
