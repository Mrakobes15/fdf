/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:37:10 by risolon           #+#    #+#             */
/*   Updated: 2022/05/07 19:37:26 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	copy_args(t_dot **arr, char *line, int width, int height)
{
	char	**split;
	int		count;

	split = ft_split(line, ' ');
	printf ("%p split\n", &split);
	count = 0;
	while (count < width)
	{
		arr[height][count].z = ft_atoi(split[count]);
		arr[height][count].y = height;
		arr[height][count].x = count;
		arr[height][count].last = 0;
		arr[height][count].color = get_color(split[count]);
		free(split[count]);
		count++;
	}
	free(split);
	arr[height][count - 1].last = 1;
}

t_dot	**init_matrix(char	*filename, t_fdf *data, t_dot **matrix)
{
	int		x;
	int		y;
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(filename, O_RDONLY, 0);
	if (fd <= 0)
		exit(1);
	line = get_next_line(fd);
	printf ("%p line init1\n", &line);
	x = ft_count_w(line, ' ');
	free(line);
	y = 0;
	while (line)
	{
		y++;
		line = get_next_line(fd);
		printf ("%p line init2\n", &line);
		printf ("%p tmp\n", &tmp);
		tmp = line;
		free(tmp);
	}
	free(line);
	data->height = y;
	data->width = x;
	matrix = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	while (y > 0)
		matrix[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
	close(fd);
	return (matrix);
}

t_dot	**parser(char *filename, t_fdf *data)
{
	int		fd;
	char	*line;
	int		count;

	data->matrix = init_matrix(filename, data, data->matrix);
	printf ("%p matr\n", &data->matrix);
	if (!data->matrix)
		exit(1);
	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	printf ("%p line par\n", &line);
	count = 0;
	while (count < data->height)
	{
		copy_args(data->matrix, line, data->width, count);
		if (line)
			free(line);
		line = get_next_line(fd);
		count++;
	}
	data->matrix[count] = NULL;
	close(fd);
	free(line);
	return (data->matrix);
}
