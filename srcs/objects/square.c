/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:14:02 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/23 11:25:30 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	in_square(t_obj *sq, t_vec3 p)
{
	t_vec3	edge[3];
	t_vec3	c[3];

	if (in_triangle(sq, p))
		return (1);
	edge[0] = sum_alg_2vec3(1, sq->c, -1, sq->b);
	edge[1] = sum_alg_2vec3(1, sq->d, -1, sq->c);
	edge[2] = sum_alg_2vec3(1, sq->b, -1, sq->d);
	c[0] = sum_alg_2vec3(1, &p, -1, sq->b);
	c[1] = sum_alg_2vec3(1, &p, -1, sq->c);
	c[2] = sum_alg_2vec3(1, &p, -1, sq->d);
	if (dot_prod(*(sq->norm), cross_prod(edge[0], c[0])) > 0
		&& dot_prod(*(sq->norm), cross_prod(edge[1], c[1])) > 0
		&& dot_prod(*(sq->norm), cross_prod(edge[2], c[2])) > 0)
		return (1);
	return (0);
}

void	complete_sq4(t_obj *sq)
{
	t_vec3	abc;
	float	d;

	if (sq->norm->x == 0 && sq->norm->y == 0 && sq->norm->z != 0)
	{
		abc.x = 1;
		abc.y = -2 * sq->center->x;
		abc.z = pow(sq->center->x, 2) - 0.5 * pow(sq->len, 2);
		d = discriminant(abc);
		sq->a->x = (-abc.y - sqrt(d)) * 0.5 / abc.x;
		sq->c->x = (-abc.y + sqrt(d)) * 0.5 / abc.x;
		sq->a->y = sq->center->y;
		sq->a->z = sq->center->z;
		sq->c->y = sq->center->y;
		sq->c->z = sq->center->z;
	}
	else
		printf("T'as un pb\n");
}
