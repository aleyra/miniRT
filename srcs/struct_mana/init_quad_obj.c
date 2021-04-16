/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_quad_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:10:55 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/16 14:51:33 by lburnet          ###   ########lyon.fr   */
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
	pl->quad->h = pl->norm->y;
	pl->quad->i = pl->norm->z;
	pl->quad->j = -pl->norm->x * pl->center->x
		- pl->norm->y * pl->center->y - pl->norm->z * pl->center->z;
}

void	init_quad_cy(t_obj *cy)
{
	cy->quad->a = pow(cy->dir->y, 2) + pow(cy->dir->z, 2);
	cy->quad->b = pow(cy->dir->x, 2) + pow(cy->dir->z, 2);
	cy->quad->c = pow(cy->dir->x, 2) + pow(cy->dir->y, 2);
	cy->quad->d = -1 * cy->dir->y * cy->dir->z;
	cy->quad->e = -1 * cy->dir->x * cy->dir->z;
	cy->quad->f = -1 * cy->dir->x * cy->dir->y;
	cy->quad->g = 2 * (cy->dir->x * cy->dir->y * cy->center->y - cy->quad->b
			* cy->center->x + cy->dir->x * cy->dir->z * cy->center->z);
	cy->quad->h = 2 * (cy->dir->x * cy->dir->y * cy->center->x - cy->quad->b
			* cy->center->y + cy->dir->y * cy->dir->z * cy->center->z);
	cy->quad->i = 2 * (cy->dir->x * cy->dir->z * cy->center->x + cy->dir->y
			* cy->dir->z * cy->center->y - cy->quad->c * cy->center->z);
	cy->quad->j = (pow(cy->center->y, 2) + pow(cy->center->z, 2) - 1) * pow(
			cy->dir->x, 2) + (pow(cy->center->x, 2) + pow(cy->center->z, 2) - 1)
		* pow(cy->dir->y, 2) + (pow(cy->center->x, 2) + pow(
				cy->center->y, 2) - 1) * pow(cy->dir->z, 2) - 2 * (cy->dir->y
			* cy->dir->z * cy->center->y *cy->center->z + cy->dir->x
			* cy->dir->z * cy->center->x * cy->center->z + cy->dir->x
			* cy->dir->y * cy->center->x * cy->center->y) - pow(
			cy->diam * 0.5, 2);
}
