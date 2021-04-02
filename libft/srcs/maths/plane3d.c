/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:08:22 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/26 13:15:21 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_plane(t_vec3 *o, t_vec3 *n, t_vec3 *p)
{
	float	e;

	e = n->x * p->x + n->y * p->y + n->z * p->z - n->x * o->x
		 - n->y * o->y - n->z * n->z;
	return (e <= 0.001f && e >= -0.001f);
}
