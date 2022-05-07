/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:25:58 by risolon           #+#    #+#             */
/*   Updated: 2022/05/07 20:17:38 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear(t_dot **data, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->height)
	{
		free(data[i]);
		printf ("%p data i\n", &data[i]);
		i++;
	}
	printf ("%p data last\n", &data[i]);
	free(data);
}

void	ft_set_data(t_fdf *data)
{
	data->matrix = NULL;
	data->height = 0;
	data->width = 0;
	data->zoom = 31;
	data->z_zoom = data->zoom / 6;
	data->angle = 0.6;
	data->isometric = 1;
	data->x_width = 2000;
	data->y_width = 1350;
	data->x_shift = data->x_width / 3;
	data->y_shift = data->y_width / 3;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->x_width,
			data->y_width, "FDF");
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc < 2)
		exit(1);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		exit(1);
	ft_set_data(data);
	printf ("%p data\n", &data);
	printf ("%p data matr\n", &data->matrix);
	printf ("%p data mlx\n", &data->mlx_ptr);
	printf ("%p data win\n", &data->win_ptr);
	parser(argv[1], data);
	ft_painter(data->matrix, data);
	mlx_key_hook(data->win_ptr, deal_keyboard, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	clear(data->matrix, data);
	free(data);
	return (0);
}
