/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:46:54 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/19 15:53:58 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	init_ray_shooter(unsigned int *err, float *r, float fovr,
		unsigned int x)
{
	*r = 2 * tan(fovr * 0.5) / x;
	*err = NO_ERROR;
	return (0);
}

static int	init_with_malloc(t_vec3 **ray, t_rgb **color)
{
	*ray = malloc(sizeof(t_vec3));
	if (!(*ray))
		return (ERROR_MALLOC);
	init_tvec3_to_0(*ray);
	*color = malloc(sizeof(t_rgb));
	if (!(*color))
	{
		free(*ray);
		return (ERROR_MALLOC);
	}
	init_struct_rgb(*color);
	return (NO_ERROR);
}

static int	end_ray_shooter(t_vec3 **ray, t_rgb **color, int err)
{
	printf("done\n");
	free(*ray);
	free(*color);
	if (err != NO_ERROR)
		return (err);
	return (NO_ERROR);
}

/******************************************************************************/
/* in this fct																  */
/* ike[0] = i a counter for pixels along of x								  */
/* ike[1] = k a counter for pixels along of z								  */
/* ike[3] = err							 									  */
/* r = R_H = R_V															  */
/******************************************************************************/
int	ray_shooter(void *img, t_mrt *mrt, t_cam *cam, t_pixel_setter put_pixel)
{
	unsigned int	ike[3];
	float			r;
	t_vec3			*ray;
	t_rgb			*color;

	ike[0] = init_ray_shooter(&(ike[2]), &r, cam->fovr, mrt->res->x);
	if (init_with_malloc(&ray, &color) != NO_ERROR)
		return (ERROR_MALLOC);
	while (ike[0] < mrt->res->x && ike[2] == NO_ERROR)
	{
		ike[1] = 0;
		while (ike[1] < mrt->res->y && ike[2] == NO_ERROR)
		{
			*ray = define_ray(ike, mrt, r, cam);
			ike[2] = ray_trace(ray, mrt, cam->ptofview, color);
			put_pixel(img, ike[0], ike[1], *color);
			ike[1]++;
		}
		ike[0]++;
	}
	return (end_ray_shooter(&ray, &color, ike[2]));
}
