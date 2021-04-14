/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:46:54 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/14 14:58:38 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//avec pls obj, stocker et comparer les t pour afficher le plus petit (donc le plus proche)
static float	shooting_sphere(t_obj *sp, t_vec3 *ray, t_vec3 *ptofview)
{
	float	t;
	t_vec3	v;

	t = 0.1;
	while (t < 100)//valeur a determiner
	{
		v = sum_alg_2vec3(t, ray, -t, ptofview);
		if (on_sphere(sp->center, sp->diam, &v) == 1)
		{
			printf("!\n");//
			return (t);
		}
		t += 0.1;
	}
	printf("-");//
	return (0);
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
	r[1] = 2 * tan(cam->fovr * mrt->res->y * 0.5 / mrt->res->x) / mrt->res->y;
	ray = malloc(sizeof(t_vec3));
	while (ik[0] < mrt->res->x)
	{
		ik[1] = 0;
		while (ik[1] < mrt->res->y)
		{
			ray->x = (ik[0] - mrt->res->x * 0.5) * r[0];
			ray->y = -1;
			ray->z = (mrt->res->y * 0.5 - ik[1]) * r[1];
			if (shooting_sphere(obj, ray, cam->ptofview) > 0)
			{
				my_mlx_pixel_put(img, ik[0], ik[1], obj->rgb->i);
			}
			ik[1]++;
			// printf("%d\t", ik[1]);//
		}
		ik[0]++;
		// printf("%d\t", ik[0]);//
	}
	printf("fini\n");//
	free(ray);
}
