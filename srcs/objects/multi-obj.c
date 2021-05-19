/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi-obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:55:17 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/19 09:52:32 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_coll	find_of_and_tf(
	t_obj **of, t_obj *obj, t_vec3 *ray, t_vec3 *ptofview)
{
	float	t;
	t_coll	f;

	*of = NULL;
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

static void	while_o(t_ray_tracer *t, int *in_shadow)
{
	t->lray.t = 0;
	if (t->o != t->fo && inter_lray(&(t->lray), t->li->lightpt, t->o))
		*in_shadow = 1;
	t->o = t->o->next;
}

//inspired by http://www.alrj.org/docs/3D/raytracer/raytracertutchap2.htm
int	ray_trace(t_vec3 *ray, t_mrt *mrt, t_vec3 *ptofview, t_rgb *c)
{
	t_ray_tracer	t;
	int				in_shadow;

	init_struct_rgb(c);
	t.tf_cac = find_of_and_tf(&(t.fo), mrt->obj, ray, ptofview);
	if (!t.fo)
		return (NO_ERROR);
	*c = color_obj_and_amb((t.fo)->rgb, mrt->amb);
	t.li = mrt->light;
	t.tmp = shooting_obj(t.fo, ray, ptofview).n;
	while (t.li)
	{
		t.o = mrt->obj;
		t.lray.n = sum_alg_2vec3(1, &(t.tf_cac.c), -1, t.li->lightpt);
		in_shadow = 0;
		while (!in_shadow && t.o)
			while_o(&t, &in_shadow);
		if (!in_shadow)
			*c = c_add(*c, calc_c(t.li, t.fo, t.tmp, opp_vec3(t.lray.n)));
		t.li = t.li->next;
	}
	float_color_to_char_int(c);
	return (NO_ERROR);
}
