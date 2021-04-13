/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:46:54 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/13 15:32:32 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/******************************************************************************/
/* in this fct																  */
/* ikt[0] = i a counter for pixels along of x								  */
/* ikt[1] = k a counter for pixels along of z								  */
/* ikt[2] = t a scalar for shooting ray										  */
/* r[0] = R_H																  */
/* r[1] = R_V																  */
/******************************************************************************/
//???????????
void	ray_shooter(t_data **img, t_mrt *mrt/*, int nb_cam*/)
{
	float	ikt[3];
	float	r[2];
	t_vec3	ray;
	t_cam	*cam;
	t_obj	*obj;

	ikt[0] = 0;
	ikt[1] = 0;
	cam = mrt->cam;
	// while (nb_cam > 0)
	// {
	// 	cam = cam->next;
	// 	nb_cam--;
	// }
	obj = mrt->obj;
	r[0] = 2 * tan(cam->fov * 0.5) / mrt->res->x;
	r[1] = 2 * tan(cam->fov * mrt->res->y * 0.5 / mrt->res->x) / mrt->res->y;
	ray = malloc(sizeof(t_vec3));
	while (ikt[0] < mrt->res->x)
	{
		while (ikt[1] < mrt->res->y)
		{
			ray->x = (ikt[0] - mrt->res->x * 0.5) * r[0];
			ray->y = -1;
			ray->z = (mrt->res->y * 0.5 - ikt[1]) * r[1];
			ikt[2] = 0;
			while (ikt[0])
			{
				if (on_sphere(obj->center, obj->diam, &ray) == 1)//lancer le rayon en utilisant le fait de Oray = {tOray, t >= 0}
				{
					my_mlx_pixel_put(*img, ikt[0], ikt[1], obj->rgb->i);
				}
				ikt[0] += 0.01;
			}
			ikt[1]++;
		}
		ikt[0]++;
	}
	free(ray);
}
