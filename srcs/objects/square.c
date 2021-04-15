/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:14:02 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/15 16:00:22 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	def_corner_square(t_obj *sq)
// {
// 	float	r1;
// 	float	r2;
// 	t_vec3	*i;
// 	t_vec3	*j;

// 	r1 = angle_one_polaris(sq->norm);
// 	r2 = angle_two_polaris(sq->norm);
// 	i = malloc(sizeof(t_vec3));
// 	j = malloc(sizeof(t_vec3));
// 	*(sq->center) = rotation_around_y(
// 			rotation_around_z(*(sq->center), -r2), -r1);
// 	init_tvec3_to_1x(i);
// 	init_tvec3_to_1y(j);
// 	*(sq->a) = sum_alg_2vec3(1, sq->norm, -0.5 * sq->len, i);
// 	*(sq->a) = sum_alg_2vec3(1, sq->a, 0.5 * sq->len, j);
// 	*(sq->b) = sum_alg_2vec3(1, sq->a, sq->len, i);
// 	*(sq->c) = sum_alg_2vec3(1, sq->b, -1 * sq->len, j);
// 	*(sq->d) = sum_alg_2vec3(1, sq->c, -1 * sq->len, i);
// 	free(i);
// 	free(j);
// 	*(sq->center) = rotation_around_z(rotation_around_y(*(sq->center), r1), r2);
// 	*(sq->a) = rotation_around_z(rotation_around_y(*(sq->a), r1), r2);
// 	*(sq->b) = rotation_around_z(rotation_around_y(*(sq->b), r1), r2);
// 	*(sq->c) = rotation_around_z(rotation_around_y(*(sq->c), r1), r2);
// 	*(sq->d) = rotation_around_z(rotation_around_y(*(sq->d), r1), r2);
// }

// int	in_square(t_obj sq, t_vec3 p)
// {
// 	if (!in_plane(sq.center, sq.norm, &p))
// 		return (0);
// 	if (!(in_angular_sector(sq.a, sq.b, sq.c, &p) && in_angular_sector(
// 				sq.c, sq.d, sq.a, &p)))
// 		return (0);
// 	return (1);
// }
