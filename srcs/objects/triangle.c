/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:04:14 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/11 13:09:50 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	in_triangle(t_obj tr, t_vec3 p)
{
	if (!in_plane(tr.a, tr.norm, p))
		return (0);
	if (!(in_angular_sector(tr.a, tr.b, tr.c, p) && in_angular_sector(
				tr.b, tr.c, tr.a, p)))
		return (0);
	return (1);
}
