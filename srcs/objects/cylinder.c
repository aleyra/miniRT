/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:04:40 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/14 11:31:57 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	on_circle(t_vec3 *center, float diam, t_vec3 *p)
{
	float	eq;

	eq = pow(p->x - center->x, 2) + pow(p->y - center->y, 2) - pow(
			diam * 0.5, 2);
	return (eq <= 0.001f && eq >= -0.001f);
}

int	on_cylinder(t_obj *cy, t_vec3 *p)
{
	float	r1;
	float	r2;

	r1 = angle_one_polaris(cy->dir);
	r2 = angle_two_polaris(cy->dir);
	*p = rotation_around_y(rotation_around_z(*p, -r2), -r1);
	*(cy->center) = rotation_around_y(
			rotation_around_z(*(cy->center), -r2), -r1);
	if (!(p->z >= cy->center->z && p->z <= cy->center->z + cy->height))
		return (0);
	if (!(on_circle(cy->center, cy->diam, p)))
		return (0);
	*p = rotation_around_z(rotation_around_y(*p, r1), r2);
	*(cy->center) = rotation_around_z(rotation_around_y(*(cy->center), r1), r2);
	return (1);
}
