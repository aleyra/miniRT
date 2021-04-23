/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_t_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:15:38 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/23 14:45:54 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	complete_tr(t_obj *tr)
{
	*(tr->norm) = normal_of_tr(tr->a, tr->b, tr->c);
}

void	complete_sq(t_obj *sq)
{
	t_vec3	v;
	t_vec3	u;
	t_vec3	r;

	init_tvec3_to_1x(&v);
	u = cross_prod(*(sq->norm), v);
	if (norme_vec3_power2(u) == 0)
		init_tvec3_to_1y(&u);
	r = vec3_rotate_axis(u, *(sq->norm), M_PI_2);
	*(sq->a) = sum_alg_2vec3(+1, &u, 1, sq->center);
	*(sq->b) = sum_alg_2vec3(+1, &r, 1, sq->center);
	*(sq->c) = sum_alg_2vec3(-1, &u, 1, sq->center);
	*(sq->d) = sum_alg_2vec3(-1, &r, 1, sq->center);
}
