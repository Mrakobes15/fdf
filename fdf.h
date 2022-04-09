/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:27:26 by risolon           #+#    #+#             */
/*   Updated: 2022/04/09 17:38:14 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/file.h>
# include "minilibx_macos/mlx.h"

typedef struct s_fdf
{
	int		height;
	int		width;
	int		**matrix;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;
typedef struct s_dot
{
	int	x;
	int	y;
	int	color;
}	t_dot;
/* GNL */
// char	*get_next_line(int fd);
// char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
// char	*get_line(char *buf, int j);
// char	*make_line(char *buf, int i);
// char	*check_line(char *line);
char	*ft_firstcheck(int fd, char *str);
char	*ft_new_str(char *s);
char	*get_next_line(int fd);
char	*ft_strchr(char *b, int c);
void	ft_strjoinhelp(char *concs, char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_next(char *s);
/* ft_strsplit.c */
int		ft_countword(char const *s);
int		ft_wordmalloc(char const *s, char **mass);
void	ft_rewriting(char const *s, char **mass);
char	**ft_strsplit(char const *s, int word);
int		ft_atoi(const char *str);
/* parser.c */
int		get_height(char *filename);
int		get_width(char *filename);
void	copy_args(int *arr, char *line, int width);
void	init_matrix(char	*filename, t_fdf *data);
void	parser(char *filename, t_fdf *data);
char	**ft_split(char const *s, char c);
int		ft_count_w(char const *s, char c);
/* painter.c */
float	ft_abs(float num);
void	draw_line(t_dot a, t_dot b, t_fdf *data);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#endif