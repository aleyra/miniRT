/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:36:30 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/19 15:04:09 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	img_clear(void *img, t_mrt *mrt)
{
	unsigned int	i;
	unsigned int	k;
	t_rgb			color;

	init_struct_rgb(&color);
	float_color_to_char_int(&color);
	i = 0;
	while (i < mrt->res->x)
	{
		k = 0;
		while (k < mrt->res->y)
		{
			my_mlx_pixel_put(img, i, k, color);
			k++;
		}
		i++;
	}
}

void	refresh(t_vars *v)
{
	printf("refreshing...\n");
	img_clear(v->img, v->mrt);
	ray_shooter(v->img, v->mrt, v->cam, (t_pixel_setter)my_mlx_pixel_put);
	mlx_put_image_to_window(v->mlx, v->win, v->img->img, 0, 0);
}
