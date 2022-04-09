/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:37:10 by risolon           #+#    #+#             */
/*   Updated: 2022/04/03 19:41:33 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *filename)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	count = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}

int	get_width(char *filename)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	count = ft_count_w(line, ' ');
	free(line);
	close(fd);
	return (count);
}

void	copy_args(int *arr, char *line, int width)
{
	char	**split;
	int		count;

	split = ft_split(line, ' ');
	count = 0;
	while (count < width)
	{
		arr[count] = ft_atoi(split[count]);
		free(split[count]);
		count++;
	}
	free(split);
}

void	init_matrix(char	*filename, t_fdf *data)
{
	int	count;

	count = 0;
	data->height = get_height(filename);
	data->width = get_width(filename);
	data->matrix = (int **)malloc(sizeof (int *) * (data->height + 1));
	while (count < data->height)
	{
		data->matrix[count] = (int *)
			malloc(sizeof(int) * (data->width + 1));
		count++;
	}
}

void	parser(char *filename, t_fdf *data)
{
	int		fd;
	char	*line;
	int		count;

	init_matrix(filename, data);
	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	if (!line)
		exit (1);
	count = 0;
	while (line != NULL && count < data->height)
	{
		copy_args(data->matrix[count], line, data->width);
		line = get_next_line(fd);
		count++;
	}
	data->matrix[count] = NULL;
	close(fd);
	free(line);
}
