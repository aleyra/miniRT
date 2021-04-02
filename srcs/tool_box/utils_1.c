/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:37:57 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/02 15:23:39 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	check_split_rgb(char **split)
{
	int	i;
	int	j;

	j = 0;
	while (split[j])
	{
		i = 0;
		while (split[j][i])
		{
			if (!ft_isdigit(split[j][i]) || i > 2)
				return (ERROR_RGB);
			i++;
		}
		j++;
	}
	if (j != 3)
	{
		free_split(split);
		return (ERROR_RGB);
	}
	return (NO_ERROR);
}

int	ft_atorgb(t_rgb *rgb, char *str)
{
	char	**split;

	split = ft_split(str, ',');
	if (check_split_rgb(split) == ERROR_RGB)
		return (ERROR_RGB);
	rgb->r = ft_atoi(split[0]);
	rgb->g = ft_atoi(split[1]);
	rgb->b = ft_atoi(split[2]);
	free_split(split);
	if ((rgb->r < 0 || rgb->r > 255) || (rgb->g < 0 || rgb->g > 255) || (
			rgb->b < 0 || rgb->b > 255))
		return (ERROR_RGB);
	return (NO_ERROR);
}

int	ft_atovec3norm(t_vec3 *v, char *str)
{
	char	**split;
	int		i;

	split = ft_split(str, ',');
	i = 0;
	while (split[i])
	{
		if (!can_atof(split[i]))
		{
			free_split(split);
			return (ERROR_VEC);
		}
		i++;
	}
	if (i != 3)
		return (ERROR_VEC);
	v->x = ft_atod(split[0]);
	v->y = ft_atod(split[1]);
	v->z = ft_atod(split[2]);
	free_split(split);
	if ((v->x < -1 || v->x > 1) || (v->y < -1 || v->y > 1) || (
			v->y < -1 || v->y > 1))
		return (ERROR_VECTOR_N);
	make_vec3_norm(v);
	return (NO_ERROR);
}

int	ft_atovec3(t_vec3 *v, char *str)
{
	char	**split;
	int		i;

	split = ft_split(str, ',');
	i = 0;
	while (split[i])
	{
		if (!can_atof(split[i]))
		{
			free_split(split);
			return (ERROR_VEC);
		}
		i++;
	}
	if (i != 3)
		return (ERROR_VEC);
	v->x = ft_atod(split[0]);
	v->y = ft_atod(split[1]);
	v->z = ft_atod(split[2]);
	free_split(split);
	return (NO_ERROR);
}
