/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_quad_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:10:55 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/14 16:42:49 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_quad_sp(t_obj *sp)
{
	sp->quad->a = 1;
	sp->quad->b = 1;
	sp->quad->c = 1;
	sp->quad->g = -2 * sp->center->x;
	sp->quad->h = -2 * sp->center->y;
	sp->quad->i = -2 * sp->center->z;
	sp->quad->j = pow(sp->center->x, 2) + pow(sp->center->y, 2) + pow(
			sp->center->z, 2) - pow(sp->diam * 0.5, 2);
}

void	init_quad_pl(t_obj *pl)
{
	pl->quad->g = pl->norm->x;
	pl->quad->g = pl->norm->y;
	pl->quad->g = pl->norm->z;
	pl->quad->g = -pl->norm->x * pl->center->x
		- pl->norm->y * pl->center->y - pl->norm->z * pl->center->z;
}

void	init_quad_cy(t_obj *cy)
{
	cy->quad->a = pow(cy->norm->y, 2) + pow(cy->norm->z, 2);
	cy->quad->b = pow(cy->norm->x, 2) + pow(cy->norm->z, 2);
	cy->quad->c = pow(cy->norm->x, 2) + pow(cy->norm->y, 2);
	cy->quad->d = -2 * cy->norm->y * cy->norm->z;
	cy->quad->e = -2 * cy->norm->x * cy->norm->z;
	cy->quad->f = -2 * cy->norm->x * cy->norm->y;
	cy->quad->g = 2(-);
	cy->quad->h = 
	cy->quad->i = 
	cy->quad->j = 
}
