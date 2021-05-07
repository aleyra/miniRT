/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intercept2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:56:37 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/07 11:27:25 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coll	inter_lir_cy(t_vec3 *lightray, t_vec3 *lightpt, t_obj *cy)
{
	t_vec3	v;
	float	d;
	int		n;
	t_coll	result;

	result.n = *lightray;
	result.t = 0;
	v = inter_quad_line_coeff(cy->quad, lightpt, lightray);
	d = discriminant(v);
	n = nb_sol(d);
	if (d == 0)
		return (result);
	d = inter_quad_line_sol(v, d);
	if (d > 0 && d < 1 && in_halfspace_inf(d, lightpt, lightray, cy)
		&& in_halfspace_sup(d, lightpt, lightray, cy))
		result.t = 1;
	return (result);
}
