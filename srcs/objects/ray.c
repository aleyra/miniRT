/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:46:54 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/19 13:52:04 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//avec pls obj, stocker et comparer les t pour afficher le plus petit (donc le plus proche) ?
float	shooting_obj(t_obj *obj, t_vec3 *ray, t_vec3 *ptofview)
{
	if (obj->type == TYPE_SPHERE)
		return (shooting_sphere(obj, ray, ptofview));
	if (obj->type == TYPE_CYLINDER)
		return (shooting_cylinder(obj, ray, ptofview));
	if (obj->type == TYPE_PLANE)
		return (shooting_plane(obj, ray, ptofview));
	return (0);
}

float	shooting_cylinder(t_obj *cy, t_vec3 *ray, t_vec3 *ptofview)
{
	t_vec3	v;
	float	d;
	int		n;

	v = inter_quad_line_coeff(cy->quad, ptofview, ray);
	d = discriminant(v);
	n = nb_sol(d);
	d = inter_quad_line_sol(v, d);
	if (in_halfspace_inf(d, ptofview, ray, cy) && in_halfspace_sup(
			d, ptofview, ray, cy))
		return (n);
	return (0);
}

float	shooting_plane(t_obj *sp, t_vec3 *ray, t_vec3 *ptofview)
{
	t_vec3	v;
	float	d;
	int		n;

	v = inter_quad_line_coeff(sp->quad, ptofview, ray);
	d = discriminant(v);
	n = nb_sol(d);
	d = inter_quad_line_sol(v, d);
	if (d > 0)
		return (n);
	return (0);
}

float	shooting_sphere(t_obj *sp, t_vec3 *ray, t_vec3 *ptofview)
{
	t_vec3	v;
	float	d;
	int		n;

	v = inter_quad_line_coeff(sp->quad, ptofview, ray);
	d = discriminant(v);
	n = nb_sol(d);
	return (n);
}

/******************************************************************************/
/* in this fct																  */
/* ikt[0] = i a counter for pixels along of x								  */
/* ikt[1] = k a counter for pixels along of z								  */
/* r[0] = R_H																  */
/* r[1] = R_V																  */
/******************************************************************************/
//eventuellement a appeler avec une cam qui sera selectionnee
void	ray_shooter(t_data *img, t_mrt *mrt)
{
	unsigned int	ik[2];
	float			r[2];
	t_vec3			*ray;
	t_cam			*cam;
	t_obj			*obj;

	ik[0] = 0;
	cam = mrt->cam;
	obj = mrt->obj;
	r[0] = 2 * tan(cam->fovr * 0.5) / mrt->res->x;
	r[1] = r[0];
	ray = malloc(sizeof(t_vec3));
	while (ik[0] < mrt->res->x)
	{
		ik[1] = 0;
		while (ik[1] < mrt->res->y)
		{
			ray->x = (ik[0] - mrt->res->x * 0.5) * r[0];
			ray->y = -1;
			ray->z = (mrt->res->y * 0.5 - ik[1]) * r[1];
			if (shooting_obj(obj, ray, cam->ptofview) > 0)
				my_mlx_pixel_put(img, ik[0], ik[1], color_displayed(
						obj->rgb, mrt->light, mrt->amb));
			ik[1]++;
		}
		ik[0]++;
	}
	printf("fini\n");//
	free(ray);
}
