/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:44:29 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/22 17:18:20 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	*lstlast_cam(t_cam *cam)
{
	if (cam == NULL)
		return (NULL);
	while (cam->next != NULL)
		cam = cam->next;
	return (cam);
}

t_light	*lstlast_light(t_light *light)
{
	if (light == NULL)
		return (NULL);
	while (light->next != NULL)
		light = light->next;
	return (light);
}

t_obj	*lstlast_obj(t_obj *obj)
{
	if (obj == NULL)
		return (NULL);
	while (obj->next != NULL)
		obj = obj->next;
	return (obj);
}
