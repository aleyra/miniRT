/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:19:04 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/12 10:48:21 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	win_close(t_vars *v)
{
	exit(ft_display_error(NO_ERROR, v->mrt));
	return (0);
}

void	refresh(t_vars *v)
{
	mlx_clear_window(v->mlx, v->win);
	printf("refresh en cours\n");
	ray_shooter(v->img, v->mrt, v->cam);
	mlx_put_image_to_window(v->mlx, v->win, v->img->img, 0, 0);
}

static void	keycode_124(t_vars *v)
{
	v->cam = v->cam->next;
	if (!(v->cam))
		v->cam = v->mrt->cam;
	printf("suivant :\t");//
	print_vec3(v->cam->dir);//
}

static void	keycode_123(t_vars *v)
{
	t_cam	*c;

	if (v->cam == v->mrt->cam)
	{
		while (v->cam->next)
			v->cam = v->cam->next;
	}
	else
	{
		c = v->cam;
		while (v->cam->next != c)
		{
			v->cam = v->cam->next;
			if (!(v->cam))
				v->cam = v->mrt->cam;
		}
	}
	printf("precedent :\t");//
	print_vec3(v->cam->dir);//
}

int	interact_key(int keycode, t_vars *v)
{
	printf("%d\n", keycode);//
	if (keycode == ESC)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(ft_display_error(NO_ERROR, v->mrt));
	}
	if (keycode == RIGHT_ARROW)
		keycode_124(v);
	if (keycode == LEFT_ARROW)
		keycode_123(v);
	refresh(v);
	return (0);
}
