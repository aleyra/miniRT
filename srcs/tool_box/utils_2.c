/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:10:46 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/23 14:31:40 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec3_rotate_axis(t_vec3 v, t_vec3 axis, float rad)
{
	t_vec3	res;

	res.x = axis.x * (axis.x * v.x + axis.y * v.y + axis.z * v.z)
		* (1 - cos(rad)) + v.x * cos(rad)
		+ (-axis.z * v.y + axis.y * v.z) * sin(rad);
	res.y = axis.y * (axis.x * v.x + axis.y * v.y + axis.z * v.z)
		* (1 - cos(rad)) + v.y * cos(rad)
		+ (axis.z * v.x - axis.x * v.z) * sin(rad);
	res.z = axis.z * (axis.x * v.x + axis.y * v.y + axis.z * v.z)
		* (1 - cos(rad)) + v.z * cos(rad)
		+ (-axis.y * v.x + axis.x * v.y) * sin(rad);
	return (res);
}
