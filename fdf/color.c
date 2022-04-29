/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:07:25 by risolon           #+#    #+#             */
/*   Updated: 2022/04/22 17:47:04 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(char *str)
{
	char	**split;
	int		color;

	color = 0xBBFAFF;
	if (ft_strchr(str, ','))
	{
		split = ft_split(str, ',');
		color = hex_to_int("0123456789abcdef", split[1]);
		free(split[0]);
		free(split[1]);
		free(split);
	}
	return (color);
}

int	set_color(t_dot a, t_dot b)
{
	int	color;

	if (a.z > b.z)
		color = a.color;
	else
		color = b.color;
	return (color);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	hex_to_int(char *alph, char *num)
{
	int	i;
	int	j;
	int	res;
	int	power;

	i = 0;
	power = 0;
	res = 0;
	while (num[i])
		i++;
	while (i-- > 2)
	{
		j = 0;
		while (ft_tolower(num[i]) != alph[j])
			j++;
		res += j * (pow(16, power));
		power++;
	}
	return (res);
}
