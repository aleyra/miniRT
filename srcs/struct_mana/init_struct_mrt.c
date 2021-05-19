/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_mrt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:20:59 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/19 10:39:51 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_struct_mrt(t_mrt **mrt)
{
	*mrt = malloc(sizeof(t_mrt));
	(*mrt)->res = malloc (sizeof(t_res));
	(*mrt)->res->x = 0;
	(*mrt)->res->y = 0;
	(*mrt)->amb = malloc (sizeof(t_ambient));
	(*mrt)->amb->ratio = 0;
	(*mrt)->amb->rgb = malloc (sizeof(t_rgb));
	init_struct_rgb((*mrt)->amb->rgb);
	(*mrt)->cam = 0;
	(*mrt)->light = 0;
	(*mrt)->obj = 0;
	(*mrt)->nb_cam = 0;
}

void	init_struct_cam(t_cam **cam)
{
	*cam = malloc(sizeof(t_cam));
	(*cam)->ptofview = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*cam)->ptofview);
	(*cam)->dir = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*cam)->dir);
	(*cam)->fovr = 0;
	(*cam)->next = 0;
}

void	init_struct_light(t_light **li)
{
	*li = malloc(sizeof(t_light));
	(*li)->lightpt = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*li)->lightpt);
	(*li)->br = 0;
	(*li)->rgb = malloc (sizeof(t_rgb));
	init_struct_rgb((*li)->rgb);
	(*li)->next = 0;
}

void	init_struct_quad(t_quad *quad)
{
	quad->a = 0;
	quad->b = 0;
	quad->c = 0;
	quad->d = 0;
	quad->e = 0;
	quad->f = 0;
	quad->g = 0;
	quad->h = 0;
	quad->i = 0;
	quad->j = 0;
}

void	init_struct_obj(t_obj **obj)
{
	*obj = malloc(sizeof(t_obj));
	(*obj)->next = 0;
	(*obj)->center = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*obj)->center);
	(*obj)->len = 0;
	(*obj)->rgb = malloc (sizeof(t_rgb));
	init_struct_rgb((*obj)->rgb);
	(*obj)->dir = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*obj)->dir);
	(*obj)->height = 0;
	(*obj)->a = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*obj)->a);
	(*obj)->b = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*obj)->b);
	(*obj)->c = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*obj)->c);
	(*obj)->d = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*obj)->d);
	(*obj)->quad = malloc (sizeof(t_quad));
	init_struct_quad((*obj)->quad);
	(*obj)->type = 0;
}
