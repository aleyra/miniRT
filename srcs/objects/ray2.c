/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:50:12 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/07 10:52:19 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coll	shooting_obj(t_obj *obj, t_vec3 *ray, t_vec3 *ptofview)
{
	t_coll	col;

	col.t = 0;
	init_tvec3_to_0(&(col.n));
	if (obj->type == TYPE_SPHERE)
		return (shooting_sphere(obj, ray, ptofview));
	if (obj->type == TYPE_CYLINDER)
		return (shooting_cylinder(obj, ray, ptofview));
	if (obj->type == TYPE_PLANE)
		return (shooting_plane(obj, ray, ptofview));
	if (obj->type == TYPE_TRIANGLE)
		return (shooting_triangle(obj, ray, ptofview));
	if (obj->type == TYPE_SQUARE)
		return (shooting_square(obj, ray, ptofview));
	return (col);
}

t_coll	shooting_sphere(t_obj *sp, t_vec3 *ray, t_vec3 *ptofview)
{
	t_vec3	v;
	float	d;
	t_coll	col;

	col.t = 0;
	init_tvec3_to_0(&(col.n));
	v = inter_quad_line_coeff(sp->quad, ptofview, ray);
	d = discriminant(v);
	d = inter_quad_line_sol(v, d);
	if (d > 0)
	{
		col.t = d;
		col.n = sum_alg_2vec3(1, ptofview, col.t, ray);
		col.n = sum_alg_2vec3(1, &(col.n), -1, sp->center);
	}
	return (col);
}

t_coll	shooting_plane(t_obj *pl, t_vec3 *ray, t_vec3 *ptofview)
{
	t_vec3	v;
	float	d;
	t_coll	col;

	col.t = 0;
	init_tvec3_to_0(&(col.n));
	v = inter_quad_line_coeff(pl->quad, ptofview, ray);
	d = discriminant(v);
	d = inter_quad_line_sol(v, d);
	if (d > 0)
	{
		col.t = d;
		col.n = *(pl->norm);
	}
	return (col);
}

t_coll	shooting_triangle(t_obj *tr, t_vec3 *ray, t_vec3 *ptofview)
{
	t_vec3	v;
	float	d;
	t_coll	col;

	col.t = 0;
	init_tvec3_to_0(&(col.n));
	v = inter_quad_line_coeff(tr->quad, ptofview, ray);
	d = discriminant(v);
	d = inter_quad_line_sol(v, d);
	if (d > 0 && in_triangle(tr, sum_alg_2vec3(1, ptofview, d, ray)) == 1)
	{
		col.t = d;
		col.n = *(tr->norm);
	}
	return (col);
}

t_coll	shooting_square(t_obj *sq, t_vec3 *ray, t_vec3 *ptofview)
{
	t_vec3	v;
	float	d;
	t_coll	col;

	col.t = 0;
	init_tvec3_to_0(&(col.n));
	v = inter_quad_line_coeff(sq->quad, ptofview, ray);
	d = discriminant(v);
	d = inter_quad_line_sol(v, d);
	if (d > 0 && in_square(sq, sum_alg_2vec3(1, ptofview, d, ray)) == 1)
	{
		col.t = d;
		col.n = *(sq->norm);
	}
	return (col);
}
