/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi-obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:55:17 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/18 14:22:06 by lburnet          ###   ########lyon.fr   */
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

//inspired by http://www.alrj.org/docs/3D/raytracer/raytracertutchap2.htm
int	ray_trace(t_vec3 *ray, t_mrt *mrt, t_vec3 *ptofview, t_rgb *color)
{
	t_ray_tracer	t;

	init_struct_rgb(color);
	t.fo = NULL;
	t.tf_cac = find_of_and_tf(&(t.fo), mrt->obj, ray, ptofview);
	if (!t.fo)
		return (NO_ERROR);
	*color = color_obj_and_amb((t.fo)->rgb, mrt->amb);
	t.li = mrt->light;
	t.temp.n = shooting_obj(t.fo, ray, ptofview).n;
	while (t.li)
	{
		t.o = mrt->obj;
		while (t.o)
		{
			t.lray.t = 0;
			t.lray.n = sum_alg_2vec3(1, &(t.tf_cac.c), -1, t.li->lightpt);
			if (t.o != t.fo)
				intercept_lightray(&(t.lray), t.li->lightpt, t.o);
			if (t.lray.t == 0)
			{
				t.temp.t = find_angle(opp_vec3(t.lray.n), t.temp.n, t.fo->type);
				*color = color_plus_light(color, t.li, t.temp.t, t.fo->rgb);
			}
			t.o = t.o->next;
		}
		t.li = t.li->next;
	}
	float_color_to_char_int(color);
	return (NO_ERROR);
}
