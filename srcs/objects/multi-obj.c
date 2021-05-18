/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi-obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:55:17 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/18 11:10:42 by lburnet          ###   ########lyon.fr   */
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

static void	while_o(t_ray_tracer *t, t_mrt *mrt, t_obj *fo)
{
	t->lray = intercept_lightray(&(t->tf_cac.c), t->li->lightpt, t->o);
	t->temp.t = find_angle(opp_vec3(t->lray.n), t->temp.n, fo->type);
	if (number_of_obj(mrt) == 1)
		t->color = color_plus_light(&(t->color), t->li, t->temp.t, t->fo->rgb);
	else if (t->o != t->fo && t->lray.t == 0)
		t->color = color_plus_light(&(t->color), t->li, t->temp.t, t->fo->rgb);
}

//inspired by http://www.alrj.org/docs/3D/raytracer/raytracertutchap2.htm
int	ray_trace(t_vec3 *ray, t_mrt *mrt, t_vec3 *ptofview)
{
	t_ray_tracer	t;

	t.fo = NULL;
	t.tf_cac = find_of_and_tf(&(t.fo), mrt->obj, ray, ptofview);
	if (!t.fo)
		return (0);
	t.color = color_obj_and_amb((t.fo)->rgb, mrt->amb);
	t.li = mrt->light;
	t.temp.n = shooting_obj(t.fo, ray, ptofview).n;
	while (t.li)
	{
		t.o = mrt->obj;
		while (t.o)
		{
			while_o(&t, mrt, t.fo);
			t.o = (t.o)->next;
		}
		t.li = t.li->next;
	}
	float_color_to_char_int(&(t.color));
	return (t.color.i);
}

t_rgb	ray_trace_bmp(t_vec3 *ray, t_mrt *mrt, t_vec3 *ptofview)
{
	t_ray_tracer	t;

	t.fo = NULL;
	t.tf_cac = find_of_and_tf(&(t.fo), mrt->obj, ray, ptofview);
	init_struct_rgb(&(t.color));
	if (!t.fo)
		return (t.color);
	t.color = color_obj_and_amb((t.fo)->rgb, mrt->amb);
	t.li = mrt->light;
	t.temp.n = shooting_obj(t.fo, ray, ptofview).n;
	while (t.li)
	{
		t.o = mrt->obj;
		while (t.o)
		{
			while_o(&t, mrt, t.fo);
			t.o = (t.o)->next;
		}
		t.li = t.li->next;
	}
	float_color_to_char_int(&(t.color));
	return (t.color);
}
