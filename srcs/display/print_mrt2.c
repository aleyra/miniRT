/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mrt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:34:28 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/19 14:35:41 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_corner_sq(t_obj *o)
{
	printf("A(%f,%f,%f)\t", o->a->x, o->a->y, o->a->z);
	printf("B(%f,%f,%f)\t", o->b->x, o->b->y, o->b->z);
	printf("C(%f,%f,%f)\t", o->c->x, o->c->y, o->c->z);
	printf("D(%f,%f,%f)\n", o->d->x, o->d->y, o->d->z);
}

void	print_vec3(t_vec3 *v)
{
	printf("(%f,%f,%f)\n", v->x, v->y, v->z);
}

void	print_rgb(t_rgb *rgb)
{
	printf("%d,%d,%d\n", rgb->r, rgb->g, rgb->b);
}

void	print_cam(t_cam *c)
{
	printf("(%f,%f,%f)\t", c->ptofview->x, c->ptofview->y, c->ptofview->z);
	printf("(%f,%f,%f)\t", c->dir->x, c->dir->y, c->dir->z);
	printf("%f\n", c->fovr);
}
