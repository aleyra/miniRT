/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:35:48 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/18 13:38:47 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_back_cam(t_mrt **mrt)
{
	t_cam	*cam;

	if ((*mrt)->cam == 0)
		init_struct_cam(&(*mrt)->cam);
	else
	{
		cam = lstlast_cam((*mrt)->cam);
		init_struct_cam(&cam->next);
	}
}

void	add_back_light(t_mrt **mrt)
{
	t_light	*light;

	if ((*mrt)->light == 0)
		init_struct_light(&(*mrt)->light);
	else
	{
		light = lstlast_light((*mrt)->light);
		init_struct_light(&light->next);
	}
}

void	add_back_obj(t_mrt **mrt)
{
	t_obj	*obj;

	((*mrt)->nb_obj)++;
	if ((*mrt)->obj == 0)
		init_struct_obj(&(*mrt)->obj);
	else
	{
		obj = lstlast_obj((*mrt)->obj);
		init_struct_obj(&obj->next);
	}
}
