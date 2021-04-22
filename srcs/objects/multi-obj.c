/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi-obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:55:17 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/22 10:50:47 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*static float	find_angle(t_vec3 a, t_vec3 b)
{
	t_vec3	an;
	t_vec3	bn;
	float	rad;
	float	c;

	an = a;
	bn = b;
	make_vec3_norm(&an);
	make_vec3_norm(&bn);
	c = an.x * bn.x + an.y * bn.y + an.z * bn.z;
	rad = acos(c);
	return (rad);
}*/

//inspired by http://www.alrj.org/docs/3D/raytracer/raytracertutchap2.htm
int	ray_trace(t_vec3 *ray, t_mrt *mrt, t_vec3 *ptofview)
{
	float	tf;
	float	t;
	t_obj	*of;
	t_obj	*obj;
	t_rgb	color;
	// t_light	*li;
	// t_vec3	nray;
	// t_coll	c;

	tf = INFINITY;
	obj = mrt->obj;
	of = NULL;
	// printf("%p\n", of);//
	while (obj)
	{
		t = shooting_obj(obj, ray, ptofview).t;
		// printf("%f",t);//
		if (t && t < tf)
		{
			tf = t;
			of = obj;
		}
		// printf("%p", of);//
		// exit(42);
		obj = obj->next;
	}
	if (!of)
		return (0);
	color = color_obj_and_amb(of->rgb, mrt->amb);
	// nray = sum_alg_2vec3(1, ptofview, tf, ray);
	// li = mrt->light;
	// while (li)
	// {
	// 	obj = mrt->obj;
	// 	while (obj)
	// 	{
	// 		if (of != obj)
	// 		{
	// 			c = shooting_obj(obj, &nray, li->lightpt);
	// 			if (c.t == 0)
	// 				color = color_plus_light(&color, li, 1 /*find_angle(
	// 							sum_alg_2vec3(
	// 								1, li->lightpt, -1, &nray), c.n)*/, of->rgb);
	// 		}
	// 		obj = obj->next;
	// 	}
	// 	li = li->next;
	// }
	return (color.i);
}
