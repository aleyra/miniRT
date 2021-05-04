/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_mrt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:34:28 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/29 13:36:10 by lburnet          ###   ########lyon.fr   */
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