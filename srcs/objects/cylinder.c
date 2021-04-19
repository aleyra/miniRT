/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:04:40 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/19 10:27:55 by lburnet          ###   ########lyon.fr   */
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

int	in_halfspace_sup(float t, t_vec3 *c, t_vec3 *r, t_obj *o)
{
	t_quad	qpl;
	t_vec3	v;

	qpl.a = 0;
	qpl.b = 0;
	qpl.c = 0;
	qpl.d = 0;
	qpl.e = 0;
	qpl.f = 0;
	qpl.g = o->norm->x;
	qpl.h = o->norm->y;
	qpl.i = o->norm->z;
	qpl.j = -qpl.g * o->center->x - qpl.h * o->center->y - qpl.i * o->center->z;
	v = inter_quad_line_coeff(&qpl, c, r);
	if (t * v.y + v.z > 0)
		return (1);
	else
		return (0);
}

int	in_halfspace_inf(float t, t_vec3 *c, t_vec3 *r, t_obj *o)
{
	t_quad	qpl;
	t_vec3	v;

	qpl.a = 0;
	qpl.b = 0;
	qpl.c = 0;
	qpl.d = 0;
	qpl.e = 0;
	qpl.f = 0;
	qpl.g = o->norm->x;
	qpl.h = o->norm->y;
	qpl.i = o->norm->z;
	qpl.j = -qpl.g * o->a->x - qpl.h * o->a->y - qpl.i * o->a->z;
	v = inter_quad_line_coeff(&qpl, c, r);
	if (t * v.y + v.z < 0)
		return (1);
	else
		return (0);
}
