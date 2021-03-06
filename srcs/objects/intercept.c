/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intercept.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:24:59 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/19 09:45:33 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	inter_lray(t_coll *lightray, t_vec3 *lightpt, t_obj *obj)
{
	if (obj->type == TYPE_SPHERE)
		return (intercept_lray_sp(&(lightray->n), lightpt, obj).t);
	if (obj->type == TYPE_CYLINDER)
		return (intercept_lray_cy(&(lightray->n), lightpt, obj).t);
	if (obj->type == TYPE_PLANE)
		return (intercept_lray_pl(&(lightray->n), lightpt, obj).t);
	if (obj->type == TYPE_TRIANGLE)
		return (intercept_lray_tr(&(lightray->n), lightpt, obj).t);
	if (obj->type == TYPE_SQUARE)
		return (intercept_lray_sq(&(lightray->n), lightpt, obj).t);
	return (0);
}

t_coll	intercept_lray_sp(t_vec3 *lightray, t_vec3 *lightpt, t_obj *sp)
{
	t_vec3	v;
	float	d;
	t_coll	result;

	result.n = *lightray;
	result.t = 0;
	v = inter_quad_line_coeff(sp->quad, lightpt, lightray);
	d = discriminant(v);
	d = inter_quad_line_sol(v, d);
	if (d > 0 && d < 1)
		result.t = 1;
	return (result);
}

t_coll	intercept_lray_pl(t_vec3 *lightray, t_vec3 *lightpt, t_obj *pl)
{
	t_vec3	v;
	float	d;
	t_coll	result;

	result.n = *lightray;
	result.t = 0;
	v = inter_quad_line_coeff(pl->quad, lightpt, lightray);
	d = discriminant(v);
	d = inter_quad_line_sol(v, d);
	if (d > 0 && d < 1)
		result.t = 1;
	return (result);
}

t_coll	intercept_lray_tr(t_vec3 *lightray, t_vec3 *lightpt, t_obj *tr)
{
	t_vec3	v;
	float	d;
	t_coll	result;

	result.n = *lightray;
	result.t = 0;
	v = inter_quad_line_coeff(tr->quad, lightpt, lightray);
	d = discriminant(v);
	d = inter_quad_line_sol(v, d);
	if (d > 0 && d < 1
		&& in_triangle(tr, sum_alg_2vec3(1, lightpt, d, lightray)) == 1)
		result.t = 1;
	return (result);
}

t_coll	intercept_lray_sq(t_vec3 *lightray, t_vec3 *lightpt, t_obj *sq)
{
	t_vec3	v;
	float	d;
	t_coll	result;

	result.n = *lightray;
	result.t = 0;
	v = inter_quad_line_coeff(sq->quad, lightpt, lightray);
	d = discriminant(v);
	d = inter_quad_line_sol(v, d);
	if (d > 0 && d < 1
		&& in_square(sq, sum_alg_2vec3(1, lightpt, d, lightray)) == 1)
		result.t = 1;
	return (result);
}
