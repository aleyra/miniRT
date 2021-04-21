/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:04:40 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/21 16:31:35 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_vec3	normal_to_cy(t_vec3 *n, t_vec3 pt, t_vec3 *o)
{
	float	t;
	t_vec3	v;

	t = (o->x - pt.x) * n->x + (o->y - pt.y) * n->y + (o->z - pt.z) * n->z;
	v.x = o->x + t * n->x - pt.x;
	v.y = o->y + t * n->y - pt.y;
	v.z = o->z + t * n->z - pt.z;
	return (v);
}
