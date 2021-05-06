/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi-obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:55:17 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/06 15:42:06 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_coll	find_of_and_tf(
	t_obj **of, t_obj *obj, t_vec3 *ray, t_vec3 *ptofview)
{
	float	t;
	t_coll	f;

	f.t = INFINITY;
	while (obj)
	{
		t = shooting_obj(obj, ray, ptofview).t;
		if (t && t < f.t)
		{
			f.t = t;
			*of = obj;
		}
		obj = obj->next;
	}
	f.c = sum_alg_2vec3(1, ptofview, f.t, ray);
	return (f);
}

static int	number_of_obj(t_mrt *mrt)
{
	int		i;
	t_obj	*obj;

	i = 0;
	obj = mrt->obj;
	while (obj)
	{
		i++;
		obj = obj->next;
	}
	return (i);
}

//inspired by http://www.alrj.org/docs/3D/raytracer/raytracertutchap2.htm
int	ray_trace(t_vec3 *ray, t_mrt *mrt, t_vec3 *ptofview)
{
	t_coll	f;
	t_obj	*o;
	t_rgb	color;
	t_light	*li;
	t_obj	*obj;
	t_coll	lray;

	o = NULL;
	f = find_of_and_tf(&o, mrt->obj, ray, ptofview);
	if (!o)
		return (0);
	color = color_obj_and_amb(o->rgb, mrt->amb);
	li = mrt->light;
	while (li)
	{
		obj = mrt->obj;
		while (obj)
		{
			lray.n = sum_alg_2vec3(1, li->lightpt, -1, &(f.c));
			lray.t = shooting_obj(obj, &(lray.n), li->lightpt).t;
			if (number_of_obj(mrt) == 1)
				color = color_plus_light(&color, li, find_angle(
							lray.n, shooting_obj(o, ray, ptofview).n), o->rgb);
			else if (obj != o && (lray.t == 0 || lray.t > 1))
				color = color_plus_light(&color, li, find_angle(
							lray.n, shooting_obj(o, ray, ptofview).n), o->rgb);
			obj = obj->next;
		}
		li = li->next;
	}
	return (color.i);
}
