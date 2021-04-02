/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delall_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:01:05 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/22 17:16:11 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	delall_cam(t_cam **cam)
{
	t_cam	*c;

	c = *cam;
	if (c->next != NULL)
		delall_cam(&c->next);
	free(c);
	*cam = NULL;
}

void	delall_light(t_light **light)
{
	t_light	*l;

	l = *light;
	if (l->next != NULL)
		delall_light(&l->next);
	free(l);
	*light = NULL;
}

void	delall_obj(t_obj **obj)
{
	t_obj	*o;

	o = *obj;
	if (o->next != NULL)
		delall_obj(&o->next);
	free(o);
	*obj = NULL;
}

void	free_mrt(t_mrt	*mrt)
{
	delall_cam(&mrt->cam);
	delall_light(&mrt->light);
	delall_obj(&mrt->obj);
	free(mrt);
}
