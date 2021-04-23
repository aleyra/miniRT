/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_t_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:15:38 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/23 11:22:49 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	complete_tr(t_obj *tr)
{
	*(tr->norm) = normal_of_tr(tr->a, tr->b, tr->c);
}

static void	complete_sq3(t_obj *sq)
{
	t_vec3	abc;
	float	d;

	if (sq->norm->x == 0 && sq->norm->y != 0)
	{
		abc.x = 1;
		abc.y = -2 * sq->center->x;
		abc.z = sq->center->x - 0.5 * pow(sq->len, 2);
		d = discriminant(abc);
		sq->a->x = (-abc.y - sqrt(d)) * 0.5 / abc.x;
		sq->c->x = (-abc.y + sqrt(d)) * 0.5 / abc.x;
		sq->a->y = sq->center->y;
		sq->a->z = sq->center->z;
		sq->c->y = sq->center->y;
		sq->c->z = sq->center->z;
	}
	else
		complete_sq4(sq);
}

static void	complete_sq2(t_obj *sq)
{
	t_vec3	abc;
	float	d;

	if (sq->norm->x == 0 && sq->norm->x == sq->norm->z && sq->norm->y != 0)
	{
		abc.x = 1;
		abc.y = -2 * sq->center->y;
		abc.z = pow(sq->center->y, 2) - 0.5 * pow(sq->len, 2);
		d = discriminant(abc);
		sq->a->y = (-abc.y - sqrt(d)) * 0.5 / abc.x;
		sq->c->y = (-abc.y + sqrt(d)) * 0.5 / abc.x;
		sq->a->x = sq->center->x;
		sq->a->z = sq->center->z;
		sq->c->x = sq->center->x;
		sq->c->z = sq->center->z;
	}
	else
		complete_sq3(sq);
}

static void	complete_sq1(t_obj *sq)
{
	t_vec3	abc;
	float	d;

	if (sq->norm->x != 0 && sq->norm->x == sq->norm->z && sq->norm->y != 0)
	{
		abc.x = 1 + pow(sq->norm->z / sq->norm->y, 2);
		abc.y = -2 * sq->center->z * abc.x;
		abc.z = pow(sq->center->z, 2) - 0.5 * pow(sq->len, 2)
			+ pow(sq->norm->z * sq->center->z / sq->norm->y, 2);
		d = discriminant(abc);
		sq->a->z = (-abc.y - sqrt(d)) * 0.5 / abc.x;
		sq->c->z = (-abc.y + sqrt(d)) * 0.5 / abc.x;
		sq->a->x = sq->center->x;
		sq->a->y = sq->center->y
			+ sq->norm->z * (sq->norm->z - sq->a->z) / sq->norm->y;
		sq->c->x = sq->center->x;
		sq->c->y = sq->center->y
			+ sq->norm->z * (sq->norm->z - sq->c->z) / sq->norm->y;
	}
	else
		complete_sq2(sq);
}

void	complete_sq(t_obj *sq)
{
	t_vec3	abc;
	float	d;

	if (sq->norm->x != 0 && sq->norm->x != sq->norm->z)
	{
		abc.x = 1 - pow(sq->norm->z / sq->norm->x, 2);
		abc.y = -2 * abc.x * sq->center->z;
		abc.z = abc.x * sq->center->z - 0.5 * pow(sq->len, 2);
		d = discriminant(abc);
		sq->a->z = (-abc.y - sqrt(d)) * 0.5 / abc.x;
		sq->c->z = (-abc.y + sqrt(d)) * 0.5 / abc.x;
		sq->a->x = sq->center->x
			+ sq->norm->z * (sq->center->z - sq->a->z) / sq->norm->x;
		sq->a->y = sq->center->y;
		sq->c->x = sq->center->x
			+ sq->norm->z * (sq->center->z - sq->c->z) / sq->norm->x;
		sq->c->y = sq->center->y;
	}
	else
		complete_sq1(sq);
}
