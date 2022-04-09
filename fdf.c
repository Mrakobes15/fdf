/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:25:58 by risolon           #+#    #+#             */
/*   Updated: 2022/04/09 19:30:16 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear(t_fdf *data)
{
	int	count;

	count = 0;
	while (count < data->height)
	{
		free(data->matrix[count]);
		count++;
	}
	free(data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;


	if (argc < 2)
		exit(1);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		exit(1);
	parser(argv[1], data);
	clear(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	mlx_loop(data->mlx_ptr);
	return (0);
}
