/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:58:22 by risolon           #+#    #+#             */
/*   Updated: 2022/04/19 16:08:23 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_dot	*a, t_dot *b, t_fdf *data)
{
	a->x *= data->zoom;
	a->y *= data->zoom;
	a->z *= data->z_zoom;
	b->x *= data->zoom;
	b->y *= data->zoom;
	b->z *= data->z_zoom;
}

void	ft_setter(t_dot *a, t_dot *b, t_fdf *data)
{
	ft_zoom(a, b, data);
	if (data->isometric == 1)
	{
		isometric(a, data);
		isometric(b, data);
	}
	a->x += data->x_shift;
	a->y += data->y_shift;
	b->x += data->x_shift;
	b->y += data->y_shift;
}
