/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:12:12 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/18 16:13:02 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coll	shooting_cylinder(t_obj *cy, t_vec3 *ray, t_vec3 *ptofview)
{
	t_vec3	v;
	float	d;
	int		n;
	t_coll	col;

	col.t = 0;
	init_tvec3_to_0(&(col.n));
	v = inter_quad_line_coeff(cy->quad, ptofview, ray);
	d = discriminant(v);
	n = nb_sol(d);
	if (d == 0)
		return (col);
	d = inter_quad_line_sol(v, d);
	if (in_halfspace_inf(d, ptofview, ray, cy) && in_halfspace_sup(
			d, ptofview, ray, cy))
	{
		col.t = d;
		col.n = normal_to_cy(
				cy->dir, sum_alg_2vec3(1, ptofview, d, ray), cy->center);
	}
	return (col);
}

t_vec3	define_ray(unsigned int ik[2], t_mrt *mrt, float r, t_cam *cam)
{
	t_vec3	ray;
	float	angle;
	t_vec3	mj;

	ray.x = (ik[0] - mrt->res->x * 0.5) * r;
	ray.y = -1;
	ray.z = (mrt->res->y * 0.5 - ik[1]) * r;
	init_tvec3_to_1y(&mj);
	mj = opp_vec3(mj);
	if (!(cam->dir->x == 0 && cam->dir->y == -1 && cam->dir->z == 0))
	{
		if (cam->dir->x > 0)
			angle = -1 * acos(-1 * cam->dir->y);
		else
			angle = acos(-1 * cam->dir->y);
		ray = vec3_rotate_axis(ray, cross_prod(*(cam->dir), mj), angle);
	}
	return (ray);
}
