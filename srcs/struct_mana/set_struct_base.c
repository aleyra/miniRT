/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:23:06 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/18 13:39:30 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	elseif_set_struct_id_obj(
	t_token token, int *i_id_nbt, t_obj *obj)
{
	if (token.val[1] == 'q')
	{
		obj->type = TYPE_SQUARE;
		i_id_nbt[1] = ID_SQUARE;
	}
	else if (token.val[1] == 'y')
	{
		obj->type = TYPE_CYLINDER;
		i_id_nbt[1] = ID_CYLINDER;
	}
	else if (token.val[1] == 'r')
	{
		obj->type = TYPE_TRIANGLE;
		i_id_nbt[1] = ID_TRIANGLE;
	}
	else
		i_id_nbt[1] = ID_ERROR;
}

void	set_struct_id_obj(t_mrt *mrt, t_token token, int *i_id_nbt)
{
	t_obj	*obj;

	add_back_obj(&(mrt));
	obj = lstlast_obj(mrt->obj);
	if (!obj || !(obj->center) || !(obj->rgb) || !(obj->a) || !(obj->b) || !(
			obj->c))
		i_id_nbt[1] = ERROR_MALLOC;
	else if (token.val[1] == 'l')
	{
		obj->type = TYPE_PLANE;
		i_id_nbt[1] = ID_PLANE;
	}
	else if (token.val[1] == 'p')
	{
		obj->type = TYPE_SPHERE;
		i_id_nbt[1] = ID_SPHERE;
	}
	else
		elseif_set_struct_id_obj(token, i_id_nbt, obj);
}

static void	elseif_set_struct_id(t_mrt *mrt, t_token token, int *i_id_nbt)
{
	t_light	*light;

	if (token.val[0] == 'l')
	{
		i_id_nbt[1] = ID_LIGHT;
		add_back_light(&(mrt));
		light = lstlast_light(mrt->light);
		if (!light || !(light->lightpt) || !(light->rgb))
			i_id_nbt[1] = ERROR_MALLOC;
	}
	else if (token.val[0] == 'R')
		i_id_nbt[1] = ID_RESOLUTION;
	else if (token.val[0] == 'A' || token.val[0] == 'a')
		i_id_nbt[1] = ID_AMBIENT_LIGHTINING;
	else
		i_id_nbt[1] = ID_ERROR;
}

void	set_struct_id(t_mrt *mrt, t_token token, int *i_id_nbt)
{
	int		len;
	t_cam	*cam;

	len = ft_strlen(token.val);
	if (len == 2)
		set_struct_id_obj(mrt, token, i_id_nbt);
	else if (len == 1)
	{
		if (token.val[0] == 'c')
		{
			i_id_nbt[1] = ID_CAMERA;
			add_back_cam(&(mrt));
			cam = lstlast_cam(mrt->cam);
			if (!cam || !(cam->ptofview) || !(cam->dir))
				i_id_nbt[1] = ERROR_MALLOC;
		}
		else
			elseif_set_struct_id(mrt, token, i_id_nbt);
	}
	else
		i_id_nbt[1] = ID_ERROR;
}

void	set_struct(t_mrt *mrt, t_token token, int *i_id_nbt)
{
	if (token.type == IDENTIFIER)
		return (set_struct_id(mrt, token, i_id_nbt));
	if (token.type == CONSTANT)
		return (set_struct_const(mrt, token, i_id_nbt));
}
