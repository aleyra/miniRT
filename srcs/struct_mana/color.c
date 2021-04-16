/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:43:39 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/16 15:12:51 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//from https://harm-smits.github.io/42docs/libs/minilibx/colors.html
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	init_color_ambiant(t_rgb *rgb, char *str)
{
	int	err;

	// printf("couleur du ficher : %s\n", str);//
	err = ft_atorgb(rgb, str);
	if (err == ERROR_RGB)
		return (ERROR_RGB);
	// printf("couleur obtenue apres atorgb %d,%d,%d\n\n", rgb->r, rgb->g, rgb->b);//
	rgb->i = create_trgb(rgb->t, rgb->r, rgb->g, rgb->b);
	rgb->fr = rgb->r / 255;
	rgb->fg = rgb->g / 255;
	rgb->fb = rgb->b / 255;
	return (NO_ERROR);
}

void	float_color_to_char_int(t_rgb *rgb)
{
	rgb->r = rgb->fr * 255;
	rgb->g = rgb->fg * 255;
	rgb->b = rgb->fb * 255;
	rgb->i = create_trgb(rgb->t, rgb->r, rgb->g, rgb->b);
}

int	init_color_obj(t_ambient *amb, t_rgb *rgb, char *str)
{
	int	err;

	//printf("couleur du ficher : %s\n", str);//
	err = ft_atorgb(rgb, str);
	if (err == ERROR_RGB)
		return (ID_BAD_RGB);
	// printf("couleur obtenue apres atorgb %d,%d,%d\n", rgb->r, rgb->g, rgb->b);//
	rgb->fr = (rgb->r / 255) * amb->rgb->fr * amb->ratio;
	rgb->fg = (rgb->g / 255) * amb->rgb->fg * amb->ratio;
	rgb->fb = (rgb->b / 255) * amb->rgb->fb * amb->ratio;
	float_color_to_char_int(rgb);
	// printf("couleur obtenue apres application de amb %d,%d,%d\n\n", rgb->r, rgb->g, rgb->b);//
	return (NO_ERROR);
}

void	add_spot(t_rgb *rgb, t_light *light)
{
	t_light	*l;

	l = light;
	while (l)
	{
		rgb->fr += rgb->fr * l->rgb->fr;
		rgb->fg += rgb->fg * l->rgb->fg;
		rgb->fb += rgb->fb * l->rgb->fb;
		l = l->next;
	}
	if (rgb->fr > 1)
		rgb->fr = 1;
	if (rgb->fg > 1)
		rgb->fg = 1;
	if (rgb->fb > 1)
		rgb->fr = 1;
	float_color_to_char_int(rgb);
}
