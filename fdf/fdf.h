/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:27:26 by risolon           #+#    #+#             */
/*   Updated: 2022/05/07 18:20:58 by risolon          ###   ########.fr       */
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

typedef struct s_dot
{
	float	x;
	float	y;
	float	z;
	int		last;
	int		color;
}	t_dot;

typedef struct s_fdf
{
	t_dot	**matrix;
	int		height;
	int		width;
	int		zoom;
	int		z_zoom;
	int		x_shift;
	int		y_shift;
	float	angle;
	int		isometric;
	int		x_width;
	int		y_width;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

/* GNL */
// char	*get_next_line(int fd);
// char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
// char	*get_line(char *buf, int j);
// char	*make_line(char *buf, int i);
// char	*check_line(char *line);
// char	*ft_firstcheck(int fd, char *str);
// char	*ft_new_str(char *s);
char	*get_next_line(int fd);
// void	*ft_calloc(size_t elementCount, size_t elementSize);
// void	ft_bzero(void *s, size_t n);
// char	*ft_strchr(const char *string, int searchedChar );
// char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(char *b, int c);
void	ft_strjoinhelp(char *concs, char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_next(char *s);
/* fdf.c */
void	clear(t_dot **data, t_fdf *fdf);
void	ft_set_data(t_fdf *data);
/* ft_strsplit.c */
int		ft_countword(char const *s);
int		ft_wordmalloc(char const *s, char **mass);
void	ft_rewriting(char const *s, char **mass);
char	**ft_strsplit(char const *s, int word);
int		ft_atoi(const char *str);
/* parser.c */
int		get_height(char *filename);
int		get_width(char *filename);
void	copy_args(t_dot **arr, char *line, int width, int height);
t_dot	**init_matrix(char	*filename, t_fdf *data, t_dot **matrix);
t_dot	**parser(char *filename, t_fdf *data);
char	**ft_split(char const *s, char c);
int		ft_count_w(char const *s, char c);
/* painter.c */
float	ft_abs(float num);
float	ft_max(float a, float b);
void	isometric(t_dot *dot, t_fdf *data);
void	draw_line(t_dot a, t_dot b, t_fdf *data);
void	ft_painter(t_dot **matrix, t_fdf *data);
/* setter.c */
void	ft_setter(t_dot *a, t_dot *b, t_fdf *data);
void	ft_zoom(t_dot	*a, t_dot *b, t_fdf *data);
/* key_hook.c */
void	key_hook(int key, t_fdf *data);
int		deal_keyboard(int key, t_fdf *data);
int		is_key(int key);
/* utils.c */
int		get_color(char *str);
int		set_color(t_dot a, t_dot b);
int		ft_tolower(int c);
int		hex_to_int(char *alph, char *num);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#endif