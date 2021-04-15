/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:39:51 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/15 14:47:34 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//give coeff a,b,c from ax^2+bx+c=0
t_vec3	inter_quad_line_coeff(t_obj *o, t_vec3 *c, t_vec3 *r)
{
	t_vec3	abc;

	abc.x = o->quad->a * pow(r->x, 2) + o->quad->b * pow(r->y, 2) + o->quad->c
		* pow(r->z, 2) + 2 * o->quad->d * r->y * r->z + 2 * o->quad->e * r->x
		* r->z + 2 * o->quad->f * r->x * r->y;
	abc.y = 2 * o->quad->a * c->x * r->x + 2 * o->quad->b * c->y * r->y + 2
		* o->quad->c * c->z * r->z + 2 * o->quad->d * c->z * r->y + 2
		* o->quad->d * c->y * r->z + 2 * o->quad->e * c->x * r->z + 2
		* o->quad->e * c->z * r->x + 2 * o->quad->f * c->x * r->y + 2
		* o->quad->f * c->y * r->x + o->quad->g * r->x + o->quad->h * r->y
		+ o->quad->i * r->z;
	abc.z = o->quad->a * pow(c->x, 2) + o->quad->b * pow(c->y, 2) + o->quad->c
		* pow(c->z, 2) + 2 * o->quad->d * c->y * c->z + 2 * o->quad->e * c->x
		* c->z + 2 * o->quad->f * c->x * c->y + o->quad->g * c->x + o->quad->h
		* c->y + o->quad->i * c->z + o->quad->j;
	return (abc);
}

//abc.a != 0 !!!!!!!
float	discriminant(t_vec3 abc)
{
	float	delta;

	if (abc.x == 0)
		return (0);
	delta = pow(abc.y, 2) - 4 * abc.x * abc.z;
	return (delta);
}

//give smaller and positive solution if possible of ax^2+bx+c=0
//need to verify the result is pos
float	inter_quad_line_sol(t_vec3 abc, float d)
{
	float	t1;
	float	t2;

	if (abc.x == 0 && abc.y != 0)
		return (-abc.z / abc.y);
	if (d == 0)
		return (abc.y * 0.5 / abc.x);
	t1 = (-abc.y - sqrt(d)) * 0.5 / abc.x;
	t2 = (-abc.y + sqrt(d)) * 0.5 / abc.x;
	if (t1 > t2 && t2 > 0)
		return (t2);
	if (t2 > t1 && t1 > 0)
		return (t1);
	if (t1 > t2)
		return (t1);
	return (t2);
}

int	nb_sol(float delta)
{
	if (delta < 0)
		return (0);
	if (delta > 0)
		return (2);
	return (1);
}
