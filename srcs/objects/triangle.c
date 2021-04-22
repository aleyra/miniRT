/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:04:14 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/22 12:48:02 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	in_triangle(t_obj *tr, t_vec3 p)
{
	t_vec3	edge[3];
	t_vec3	c[3];

	edge[0] = sum_alg_2vec3(1, tr->b, -1, tr->a);
	edge[1] = sum_alg_2vec3(1, tr->c, -1, tr->b);
	edge[2] = sum_alg_2vec3(1, tr->a, -1, tr->c);
	c[0] = sum_alg_2vec3(1, &p, -1, tr->a);
	c[1] = sum_alg_2vec3(1, &p, -1, tr->b);
	c[2] = sum_alg_2vec3(1, &p, -1, tr->c);
	if (dot_prod(*(tr->norm), cross_prod(edge[0], c[0])) > 0
		&& dot_prod(*(tr->norm), cross_prod(edge[1], c[1])) > 0
		&& dot_prod(*(tr->norm), cross_prod(edge[2], c[2])) > 0)
		return (1);
	return (0);
}
