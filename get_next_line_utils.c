/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils 2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:22:44 by acash             #+#    #+#             */
/*   Updated: 2022/04/05 15:57:30 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
