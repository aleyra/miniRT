/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:46:54 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/14 11:41:01 by lburnet          ###   ########lyon.fr   */
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

static t_vec3	define_ray(unsigned int ik[2], t_mrt *mrt, float r, t_cam *cam)
{
	t_vec3	ray;
	float	angle;
	t_vec3	mj;
	t_vec3	i;
	float	t;

	ray.x = (ik[0] - mrt->res->x * 0.5) * r;
	ray.y = -1;
	ray.z = (mrt->res->y * 0.5 - ik[1]) * r;
	init_tvec3_to_1x(&i);
	init_tvec3_to_1y(&mj);
	mj = opp_vec3(mj);
	if (!(cam->dir->x == 0 && cam->dir->y == -1 && cam->dir->z == 0))
	{
		t = dot_prod(*(cam->dir), mj);
		angle = acos(t);
		t = dot_prod(*(cam->dir), i);
		if (t > 0)
			angle *= -1;
		ray = vec3_rotate_axis(ray, cross_prod(*(cam->dir), mj), angle);
	}
	return (ray);
}

/******************************************************************************/
/* in this fct																  */
/* ikt[0] = i a counter for pixels along of x								  */
/* ikt[1] = k a counter for pixels along of z								  */
/* r = R_H = R_V															  */
/******************************************************************************/
void	ray_shooter(t_data *img, t_mrt *mrt, t_cam *cam)
{
	unsigned int	ik[2];
	float			r;
	t_vec3			ray;

	ik[0] = 0;
	r = 2 * tan(cam->fovr * 0.5) / mrt->res->x;
	while (ik[0] < mrt->res->x)
	{
		ik[1] = 0;
		while (ik[1] < mrt->res->y)
		{
			ray = define_ray(ik, mrt, r, cam);
			my_mlx_pixel_put(img, ik[0], ik[1], ray_trace(
					&ray, mrt, cam->ptofview));
			ik[1]++;
		}
		ik[0]++;
	}
	printf("done\n");
}

void	ray_shooter_bmp(t_bmp *bmp, t_mrt *mrt, t_cam *cam)
{
	unsigned int	ik[2];
	float			r;
	t_vec3			ray;

	ik[0] = 0;
	r = 2 * tan(cam->fovr * 0.5) / mrt->res->x;
	while (ik[0] < mrt->res->x)
	{
		ik[1] = 0;
		while (ik[1] < mrt->res->y)
		{
			ray = define_ray(ik, mrt, r, cam);
			pixel_data_bmp(bmp, ik[0], ik[1], ray_trace_bmp(
					&ray, mrt, cam->ptofview));
			ik[1]++;
		}
		ik[0]++;
	}
}
