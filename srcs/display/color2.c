/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:44:02 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/19 09:41:09 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	c_add(t_rgb color1, t_rgb color2)
{
	t_rgb	color;

	color.fr = color1.fr + color2.fr;
	color.fg = color1.fg + color2.fg;
	color.fb = color1.fb + color2.fb;
	return (color);
}

t_rgb	calc_c(t_light *li, t_obj *obj, t_vec3 ray, t_vec3 lray)
{
	t_rgb	rl;
	float	angle;

	angle = find_angle(ray, lray, obj->type);
	rl.fr = obj->rgb->fr * li->rgb->fr * li->br * li->br * angle;
	rl.fg = obj->rgb->fg * li->rgb->fg * li->br * li->br * angle;
	rl.fb = obj->rgb->fb * li->rgb->fb * li->br * li->br * angle;
	return (rl);
}
