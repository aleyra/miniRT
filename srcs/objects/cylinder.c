/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:04:40 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/14 15:02:11 by lburnet          ###   ########lyon.fr   */
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
	qpl.j = -qpl.g * o->b->x - qpl.h * o->b->y - qpl.i * o->b->z;
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
	t_vec3	coeff;
	float	d;

	coeff.x = -1;
	coeff.y = dot_prod(*n, sum_alg_2vec3(1, &pt, -1, o));
	coeff.z = 0;
	d = discriminant(coeff);
	t = (coeff.y + sqrt(d)) * 0.5;
	v.x = pt.x - t * n->x - o->x;
	v.y = pt.y - t * n->y - o->y;
	v.z = pt.z - t * n->z - o->z;
	if (dot_prod(*n, v) == 0)
		return (v);
	t = (coeff.y - sqrt(d)) * 0.5;
	v.x = pt.x - t * n->x - o->x;
	v.y = pt.y - t * n->y - o->y;
	v.z = pt.z - t * n->z - o->z;
	return (v);
}
