/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:37:10 by risolon           #+#    #+#             */
/*   Updated: 2022/04/29 17:03:06 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	get_height(char *filename)
// {
// 	int		fd;
// 	char	*buffer;
// 	int		count;

// 	fd = open(filename, O_RDONLY, 0);
// 	buffer = (char *)malloc(2);
// 	count = 0;
// 	if (!buffer)
// 		return (-1);
// 	while ((read(fd, buffer, 1)) > 0)
// 	{
// 		if (buffer[0] == '\n')
// 			count++;
// 	}
// 	free(buffer);
// 	return (count);
// }

// int	get_width(char *filename)
// {
// 	int		fd;
// 	char	*line;
// 	int		count;

// 	fd = open(filename, O_RDONLY, 0);
// 	line = get_next_line(fd);
// 	count = ft_wdcounter(line, ' ');
// 	free(line);
// 	close(fd);
// 	return (count);
// }

void	copy_args(t_dot **arr, char *line, int width, int height)
{
	char	**split;
	int		count;

	split = ft_split(line, ' ');
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
	free(line);
	arr[height][count - 1].last = 1;
}

t_dot	**init_matrix(char	*filename, t_fdf *data, t_dot **matrix)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	if (fd <= 0)
		exit(1);
	line = get_next_line(fd);
	x = ft_count_w(line, ' ');
	free(line);
	y = 0;
	while (get_next_line(fd) > 0)
	{
		y++;
	}
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
	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	if (!line)
		exit (1);
	count = 0;
	while (line != NULL && count < data->height)
	{
		copy_args(data->matrix, line, data->width, count);
		line = get_next_line(fd);
		count++;
	}
	data->matrix[count] = NULL;
	close(fd);
	free(line);
	return (data->matrix);
}
