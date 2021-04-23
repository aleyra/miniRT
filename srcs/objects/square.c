/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:14:02 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/23 15:11:08 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static int	orient(t_vec3 *a, t_vec3 *b, t_vec3 *c, t_vec3 *n)
// {
// 	int	result;

// 	result = dot_prod(cross_prod(sum_alg_2vec3(1, b, -1, a), sum_alg_2vec3(
// 					1, c, -1, a)), *n);
// 	if (result > 0)
// 		return (1);
// 	if (result < 0)
// 		return (-1);
// 	return (0);
// }

// int	in_square(t_obj *sq, t_vec3 p)
// {
// 	int	in;

// 	in = orient(&p, sq->a, sq->b, sq->norm);
// 	in += orient(&p, sq->b, sq->c, sq->norm);
// 	in += orient(&p, sq->c, sq->d, sq->norm);
// 	in += orient(&p, sq->d, sq->a, sq->norm);
// 	if (in == 4 || in == -4)
// 		return (1);
// 	return (0);
// }

int	in_square(t_obj *sq, t_vec3 p)
{
	t_vec3	edge[4];
	t_vec3	c[4];

	edge[0] = sum_alg_2vec3(1, sq->b, -1, sq->a);
	edge[1] = sum_alg_2vec3(1, sq->c, -1, sq->b);
	edge[2] = sum_alg_2vec3(1, sq->d, -1, sq->c);
	edge[3] = sum_alg_2vec3(1, sq->a, -1, sq->d);
	c[0] = sum_alg_2vec3(1, &p, -1, sq->a);
	c[1] = sum_alg_2vec3(1, &p, -1, sq->b);
	c[2] = sum_alg_2vec3(1, &p, -1, sq->c);
	c[3] = sum_alg_2vec3(1, &p, -1, sq->d);
	if (dot_prod(*(sq->norm), cross_prod(edge[0], c[0])) > 0
		&& dot_prod(*(sq->norm), cross_prod(edge[1], c[1])) > 0
		&& dot_prod(*(sq->norm), cross_prod(edge[2], c[2])) > 0
		&& dot_prod(*(sq->norm), cross_prod(edge[3], c[3])) > 0)
		return (1);
	return (0);
}

