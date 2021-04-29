/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:43:39 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/29 13:08:12 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//from https://harm-smits.github.io/42docs/libs/minilibx/colors.html
int	create_trgb(int t, int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
		exit(17);
	return (t << 24 | r << 16 | g << 8 | b);
}

int	init_color_initial(t_rgb *rgb, char *str)
{
	int	err;

	err = ft_atorgb(rgb, str);
	if (err == ERROR_RGB)
		return (ERROR_RGB);
	rgb->i = create_trgb(rgb->t, rgb->r, rgb->g, rgb->b);
	rgb->fr = rgb->r / 255;
	rgb->fg = rgb->g / 255;
	rgb->fb = rgb->b / 255;
	return (NO_ERROR);
}

void	float_color_to_char_int(t_rgb *rgb)
{
	rgb->r = rgb->fr * 255;
	if (rgb->r > 255)
		rgb->r = 255;
	rgb->g = rgb->fg * 255;
	if (rgb->g > 255)
		rgb->g = 255;
	rgb->b = rgb->fb * 255;
	if (rgb->b > 255)
		rgb->b = 255;
	rgb->i = create_trgb(rgb->t, rgb->r, rgb->g, rgb->b);
}

t_rgb	color_obj_and_amb(t_rgb *objc, t_ambient *amb)
{
	t_rgb	rl;

	rl.fr = objc->fr * amb->rgb->fr * amb->ratio;
	rl.fg = objc->fg * amb->rgb->fg * amb->ratio;
	rl.fb = objc->fb * amb->rgb->fb * amb->ratio;
	float_color_to_char_int(&rl);
	return (rl);
}

t_rgb	color_plus_light(t_rgb *color, t_light *light, float angle)
{
	t_rgb	rl;

	rl = *color;
	rl.fr += light->rgb->fr * light->br * angle;
	rl.fg += light->rgb->fg * light->br * angle;
	rl.fb += light->rgb->fb * light->br * angle;
	float_color_to_char_int(&rl);
	return (rl);
}

int	color_displayed(t_rgb *rgbo, t_light *light, t_ambient *amb, t_coll col, t_vec3 p)//vouer a disparaitre
{
	t_light	*l;
	t_rgb	rl;
	float	angle;
	t_vec3	an;
	t_vec3	bn;

	l = light;
	rl = color_obj_and_amb(rgbo, amb);
	while (l)
	{
		an = sum_alg_2vec3(1, l->lightpt, -1, &p);
		bn = col.n;
		angle = find_angle(an, bn);
		rl = color_plus_light(&rl, l, angle);
		l = l->next;
	}
	float_color_to_char_int(&rl);
	return (rl.i);
}
