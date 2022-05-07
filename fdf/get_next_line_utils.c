/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:22:44 by acash             #+#    #+#             */
/*   Updated: 2022/05/07 18:20:05 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		sizetotal;
// 	char	*res;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	sizetotal = ft_strlen(s1) + ft_strlen(s2);
// 	res = malloc(sizeof(char) * (sizetotal + 1));
// 	if (!res || !s1 || !s2)
// 		return (NULL);
// 	while (s1[i] != 0)
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != 0)
// 	{
// 		res[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	res[sizetotal] = 0;
// 	return (res);
// }

// char	*ft_strchr(const char *string, int searchedChar )
// {
// 	char	*str;

// 	str = (char *)string;
// 	while (*str != searchedChar && *str != 0)
// 		str++;
// 	if (*str == searchedChar)
// 		return (str);
// 	else
// 		return (NULL);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	char	*str;
// 	size_t	i;

// 	str = (char *)s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		str[i] = '\0';
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t elementCount, size_t elementSize)
// {
// 	char	*res;

// 	res = malloc(elementSize * elementCount);
// 	if (!res)
// 		return (NULL);
// 	ft_bzero(res, elementSize * elementCount);
// 	return (res);
// }

// char	*ft_strchr(char *b, int c)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!b)
// 		return (NULL);
// 	while (b[i])
// 	{
// 		if (b[i] == (char)c)
// 		{
// 			return (&b[i]);
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

// void	ft_strjoinhelp(char *concs, char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	if (s1)
// 	{
// 		while (s1[i])
// 		{
// 			concs[i] = s1[i];
// 			i++;
// 		}
// 	}
// 	while (s2[j])
// 	{
// 		concs[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	concs[i] = '\0';
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*concs;

// 	if (!s1)
// 	{
// 		s1 = malloc(1 * sizeof(char));
// 		if (s1 == NULL)
// 			return (NULL);
// 		s1[0] = '\0';
// 	}
// 	if (!s2)
// 		return (NULL);
// 	concs = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (concs == NULL)
// 		return (NULL);
// 	ft_strjoinhelp(concs, s1, s2);
// 	free(s1);
// 	return (concs);
// }

// char	*ft_next(char *s)
// {
// 	size_t	i;
// 	char	*line;

// 	i = 0;
// 	if (!s[i])
// 		return (NULL);
// 	while (s[i] && s[i] != '\n')
// 		i++;
// 	line = malloc(sizeof(char) * (i + 2));
// 	if (line == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s[i] && s[i] != '\n')
// 	{
// 		line[i] = s[i];
// 		i++;
// 	}
// 	if (s[i] == '\n')
// 	{
// 		line[i] = '\n';
// 		i++;
// 	}
// 	line[i] = '\0';
// 	return (line);
// }

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *b, int c)
{
	size_t	i;

	i = 0;
	if (!b)
		return (NULL);
	while (b[i])
	{
		if (b[i] == (char)c)
		{
			return (&b[i]);
		}
		i++;
	}
	return (NULL);
}

void	ft_strjoinhelp(char *concs, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			concs[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		concs[i] = s2[j];
		i++;
		j++;
	}
	concs[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*concs;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	concs = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (concs == NULL)
		return (NULL);
	ft_strjoinhelp(concs, s1, s2);
	free(s1);
	return (concs);
}

char	*ft_next(char *s)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}