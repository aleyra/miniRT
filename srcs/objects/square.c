/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:14:02 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/17 11:01:02 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	in_square(t_obj sq, t_vec3 p)
{
	if (!in_plane(sq.center, sq.norm, p))
		return (0);
	if (!(in_angular_sector(sq.a, sq.b, sq.c, p) && in_angular_sector(
				sq.c, sq.d, sq.a, p)))
		return (0);
	return (1);
}
