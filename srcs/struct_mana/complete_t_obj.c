/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_t_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:15:38 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/15 15:42:57 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	complete_tr(t_obj *tr)
{
	*(tr->norm) = normal_of_tr(tr->a, tr->b, tr->c);
}

// void	complete_sq(t_obj *sq)
// {
// 	float	r1;
// 	float	r2;
// 	t_vec3	i;
// 	t_vec3	j;
// 	t_vec3	tmp;

// 	r1 = angle_one_polaris(sq->norm);
// 	r2 = angle_two_polaris(sq->norm);
// 	init_tvec3_to_1x(&i);
// 	init_tvec3_to_1y(&j);
// 	tmp = sum_alg_2vec3(1, sq->center, -0.5 * sq->len, &i);
// 	*(sq->a) = sum_alg_2vec3(1, &tmp, 0.5 * sq->len, &j);
// 	*(sq->b) = sum_alg_2vec3(1, sq->a, -sq->len, &j);
// 	*(sq->c) = sum_alg_2vec3(1, sq->b, sq->len, &i);
// 	*(sq->d) = sum_alg_2vec3(1, sq->c, sq->len, &j);
// 	*(sq->a) = rotation_around_z(rotation_around_y(*(sq->a), r1), r2);
// 	*(sq->b) = rotation_around_z(rotation_around_y(*(sq->b), r1), r2);
// 	*(sq->c) = rotation_around_z(rotation_around_y(*(sq->c), r1), r2);
// 	*(sq->d) = rotation_around_z(rotation_around_y(*(sq->d), r1), r2);
// }
