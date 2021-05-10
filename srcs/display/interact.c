/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:19:04 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/10 13:09:59 by lucille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* ************************************************************************** */
/* 53 = ESC																	  */
/* 123 = LEFT ARROW														  */
/* 124 = RIGHT ARROW															  */
/* 125 = DOWN ARROW															  */
/* 126 = UP ARROW															  */
/* ************************************************************************** */

int	close(int keycode, t_vars *v)
{
	mlx_destroy_window(v->mlx, v->win);
	exit(ft_display_error(NO_ERROR, v->mrt));
	return (0);
}

void	refresh(t_vars *v)
{
	mlx_clear_window(v->mlx, v->win);
	ray_shooter(v->img, v->mrt, v->cam);
	mlx_put_image_to_window(v->mlx, v->win, v->img->img, 0, 0);
}

int	interact_key(int keycode, t_vars *v)
{
	t_cam	*c;
	printf("%d\n", keycode);//
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(ft_display_error(NO_ERROR, v->mrt));
	}
	if (keycode == 124)
	{
		v->cam = v->cam->next;
		if (!(v->cam))
			v->cam = v->mrt->cam;
		printf("suivant :\t");//
		print_vec3(v->cam->dir);//
		//ray_shooter(v->img, v->mrt, v->cam);
		//mlx_put_image_to_window(v->mlx, v->win, v->img->img, 0, 0);
	}
	if (keycode == 123)
	{
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
		//ray_shooter(v->img, v->mrt, v->cam);
		//mlx_put_image_to_window(v->mlx, v->win, v->img->img, 0, 0);
	}
	refresh(v);
	return (0);
}
