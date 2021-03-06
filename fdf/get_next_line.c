/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:21:32 by acash             #+#    #+#             */
/*   Updated: 2022/05/07 18:19:40 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static char	*ft_firstcheck(int fd, char *str)
// {
// 	char	*buff;
// 	int		rd;

// 	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (buff == NULL)
// 		return (NULL);
// 	rd = 1;
// 	while (rd != 0 && !ft_strchr(str, '\n'))
// 	{
// 		rd = read(fd, buff, BUFFER_SIZE);
// 		if (rd == -1)
// 		{
// 			free(buff);
// 			return (NULL);
// 		}
// 		buff[rd] = '\0';
// 		str = ft_strjoin(str, buff);
// 	}
// 	free (buff);
// 	return (str);
// }

// static char	*ft_new_str(char *s)
// {
// 	char	*str;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (s[i] && s[i] != '\n')
// 		i++;
// 	if (!s[i])
// 	{
// 		free(s);
// 		return (NULL);
// 	}
// 	str = malloc((ft_strlen(s) - i + 1) * sizeof(char));
// 	if (str == NULL)
// 		return (NULL);
// 	i++;
// 	while (s[i])
// 		str[j++] = s[i++];
// 	str[j] = '\0';
// 	free(s);
// 	return (str);
// }

// static char	*ft_next(char *buffer)
// {
// 	int		i;
// 	int		j;
// 	char	*line;

// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	if (!buffer[i])
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
// 	i++;
// 	j = 0;
// 	while (buffer[i])
// 		line[j++] = buffer[i++];
// 	free(buffer);
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*str;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	str = ft_firstcheck(fd, str);
// 	if (str == NULL)
// 		return (NULL);
// 	line = ft_next(str);
// 	str = ft_new_str(str);
// 	return (line);
// }

// char	*ft_free(char *buffer, char *buf)
// {
// 	char	*temp;

// 	temp = ft_strjoin(buffer, buf);
// 	free(buffer);
// 	return (temp);
// }

// // delete line find

// // take line for return
// char	*ft_line(char *buffer)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	// if no line return NULL
// 	if (!buffer[i])
// 		return (NULL);
// 	// go to the eol
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	// malloc to eol
// 	line = ft_calloc(i + 2, sizeof(char));
// 	i = 0;
// 	// line = buffer
// 	while (buffer[i] && buffer[i] != '\n')
// 	{
// 		line[i] = buffer[i];
// 		i++;
// 	}
// 	// if eol is \0 or \n, replace eol by \n
// 	if (buffer[i] && buffer[i] == '\n')
// 		line[i++] = '\n';
// 	return (line);
// }

// char	*read_file(int fd, char *res)
// {
// 	char	*buffer;
// 	int		byte_read;

// 	// malloc if res dont exist
// 	if (!res)
// 		res = ft_calloc(1, 1);
// 	// malloc buffer
// 	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	byte_read = 1;
// 	while (byte_read > 0)
// 	{
// 		// while not eof read
// 		byte_read = read(fd, buffer, BUFFER_SIZE);
// 		if (byte_read == -1)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		// 0 to end for leak
// 		buffer[byte_read] = 0;
// 		// join and free
// 		res = ft_free(res, buffer);
// 		// quit if \n find
// 		if (ft_strchr(buffer, '\n'))
// 			break ;
// 	}
// 	free(buffer);
// 	return (res);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*line;

// 	// error handling
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
// 		return (NULL);
// 	buffer = read_file(fd, buffer);
// 	if (!buffer)
// 		return (NULL);
// 	line = ft_line(buffer);
// 	buffer = ft_next(buffer);
// 	return (line);
// }

char	*ft_firstcheck(int fd, char *str)
{
	char	*buff;
	int		rd;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	rd = 1;
	while (rd != 0 && !ft_strchr(str, '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*ft_new_str(char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = malloc((ft_strlen(s) - i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i++;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_firstcheck(fd, str);
	if (str == NULL)
		return (NULL);
	line = ft_next(str);
	str = ft_new_str(str);
	return (line);
}
