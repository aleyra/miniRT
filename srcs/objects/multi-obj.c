/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi-obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:55:17 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/21 16:05:54 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Methode GetLightAt(Vector3D normal, Vector3D intersection, Material matl) retourne Couleur
//     Calculer le vecteur LIGHTVECTOR correspondant au vecteur partant de la source de lumiére jusqu'au point d'intersection avec l'objet (2.1)
//     Normaliser LIGHTVECTOR 

//     Calculer l'angle de frappe ANGLE du rayon lumineux avec la surface en utilisant la normale au point d'intersection (2.2)
//     Si ANGLE <= 0 Alors
//         COULEURFINALE = Couleur de fond
//     Sinon
//         COULEURFINALE = mDiffuseColor(mat) * couleur lumiére * ANGLE; (2.3)
//     fsi

//     Retourne COULEURFINALE
// Fin Methode GetLightAt. 

float	find_angle(t_vec3 a, t_vec3 b)
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
}

//inspired by http://www.alrj.org/docs/3D/raytracer/raytracertutchap2.htm
int	*ray_trace(t_vec3 *ray, t_mrt *mrt, t_vec3 *ptofview)
{
	float	tf;
	float	t;
	t_obj	*of;
	t_obj	*obj;
	t_rgb	color;
	t_light	*li;
	t_vec3	*nray;
	t_coll	col;

	tf = -1;
	obj = mrt->obj;
	of = NULL;
	while (obj)
	{
		t = shooting_obj(obj, ray, ptofview).t;
		if (tf < 0 || t < tf)
		{
			tf = t;
			of = obj;
		}
		obj = obj->next;
	}
	if (!of)
		return (0);
	color = color_obj_and_amb(of->rgb, mrt->amb);
	*nray = sum_alg_2vec3(1, ptofview, tf, ray);
	li = mrt->light;
	while (li)
	{
		obj = mrt->obj;
		while (obj)
		{
			if (of != obj)
			{
				col = shooting_obj(obj, nray, li->lightpt);
				if (col.t == 0)
					color = color_plus_light(&color, li, find_angle(
								sum_alg_2vec3(
									1, li->lightpt, -1, nray), col.n), of);
			}
			obj = obj->next;
		}
		li = li->next;
	}
	return (color.i);
}
