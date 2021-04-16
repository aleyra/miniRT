/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_mrt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:20:59 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/16 10:46:20 by lburnet          ###   ########lyon.fr   */
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
	(*mrt)->amb->rgb->i = 0;
	(*mrt)->amb->rgb->t = 0;
	(*mrt)->amb->rgb->b = 0;
	(*mrt)->amb->rgb->g = 0;
	(*mrt)->amb->rgb->r = 0;
	(*mrt)->amb->rgb->fb = 0;
	(*mrt)->amb->rgb->fg = 0;
	(*mrt)->amb->rgb->fr = 0;
	(*mrt)->cam = 0;
	(*mrt)->light = 0;
	(*mrt)->obj = 0;
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
	(*li)->rgb->i = 0;
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
	(*obj)->rgb->i = 0;
	(*obj)->dir = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*obj)->dir);
	(*obj)->height = 0;
	(*obj)->a = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*obj)->a);
	(*obj)->b = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*obj)->b);
	(*obj)->c = malloc (sizeof(t_vec3));
	init_tvec3_to_0((*obj)->c);
	(*obj)->quad = malloc (sizeof(t_quad));
	init_struct_quad((*obj)->quad);
	(*obj)->type = 0;
}
