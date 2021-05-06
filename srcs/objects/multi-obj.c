/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi-obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:55:17 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/06 14:54:53 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	find_of_and_tf(
	t_obj **of, t_obj *obj, t_vec3 *ray, t_vec3 *ptofview)
{
	float	t;
	float	tf;

	tf = INFINITY;
	while (obj)
	{
		t = shooting_obj(obj, ray, ptofview).t;
		if (t && t < tf)
		{
			tf = t;
			*of = obj;
		}
		obj = obj->next;
	}
	return (tf);
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
	float	tf;
	t_obj	*of;
	t_rgb	color;
	t_vec3	contact;
	t_light	*li;
	t_obj	*obj;
	t_vec3	lray;
	t_coll	c;

	of = NULL;
	tf = find_of_and_tf(&of, mrt->obj, ray, ptofview);
	if (!of)
		return (0);
	color = color_obj_and_amb(of->rgb, mrt->amb);
	contact = sum_alg_2vec3(1, ptofview, tf, ray);
	li = mrt->light;
	while (li)
	{
		obj = mrt->obj;
		while (obj)
		{
			lray = sum_alg_2vec3(1, li->lightpt, -1, &contact);
			c = shooting_obj(of, ray, ptofview);
			if (number_of_obj(mrt) > 1 && obj != of
				&& shooting_obj(obj, &lray, li->lightpt).t == 0)
				color = color_plus_light(&color, li, find_angle(lray, c.n), of->rgb);
			else if (number_of_obj(mrt) == 1)
				color = color_plus_light(&color, li, find_angle(lray, c.n), of->rgb);
			obj = obj->next;
		}
		li = li->next;
	}
	return (color.i);
}
