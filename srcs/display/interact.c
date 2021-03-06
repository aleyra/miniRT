/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:19:04 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/19 16:15:13 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	win_close(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->win);
	free(v->img);
	exit(ft_display_error(NO_ERROR, v->mrt));
	return (0);
}

static void	keycode_124(t_vars *v)
{
	v->num_cam++;
	v->num_cam = v->num_cam % v->mrt->nb_cam;
	v->cam = v->cam->next;
	if (!(v->cam))
		v->cam = v->mrt->cam;
	printf("cam no %d\t", v->num_cam);
	print_cam(v->cam);
	refresh(v);
}

static void	keycode_123(t_vars *v)
{
	int		i;

	v->num_cam--;
	if (v->num_cam < 0)
		v->num_cam = v->mrt->nb_cam - 1;
	i = 0;
	v->cam = v->mrt->cam;
	while (i != v->num_cam)
	{
		v->cam = v->cam->next;
		i++;
	}
	printf("cam no %d\t", v->num_cam);
	print_cam(v->cam);
	refresh(v);
}

int	interact_key(int keycode, t_vars *v)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(v->mlx, v->win);
		free(v->img);
		exit(ft_display_error(NO_ERROR, v->mrt));
	}
	if (keycode == RIGHT_ARROW)
	{
		keycode_124(v);
	}
	if (keycode == LEFT_ARROW)
	{
		keycode_123(v);
	}
	return (0);
}
