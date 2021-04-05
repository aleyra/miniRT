/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:08:39 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/05 14:47:42 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_struct_ambiant(t_mrt *mrt, t_token token, int *i_id_nbt)
{
	if (i_id_nbt[2] == 2)
	{
		if (!can_atof(token.val))
			i_id_nbt[1] = ID_BAD_A_RAT;
		else
		{
			mrt->amb->ratio = ft_atod(token.val);
			if (mrt->amb->ratio < 0 || mrt->amb->ratio > 1)
				i_id_nbt[1] = ID_BAD_A_RAT;
		}
	}
	else if (i_id_nbt[2] == 3)
	{
		if (ft_atorgb(mrt->amb->rgb, token.val) == ERROR_RGB)
			i_id_nbt[1] = ID_BAD_RGB;
	}
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
}

void	set_struct_cam(t_mrt *mrt, t_token token, int *i_id_nbt)
{
	t_cam	*cam;
	int		err;

	cam = lstlast_cam(mrt->cam);
	if (i_id_nbt[2] == 2)
	{
		if (ft_atovec3(cam->ptofview, token.val) == ERROR_VEC)
			i_id_nbt[1] = ID_BAD_PT;
	}
	else if (i_id_nbt[2] == 3)
	{
		err = ft_atovec3norm(cam->dir, token.val);
		if (err != NO_ERROR)
			i_id_nbt[1] = err;
	}
	else if (i_id_nbt[2] == 4)
	{
		if (!can_atoi(token.val))
			i_id_nbt[1] = ID_BAD_FOV;
		else
		{
			cam->fov = ft_atoi(token.val);
			if (cam->fov < 0 || cam->fov > 180)
				i_id_nbt[1] = ID_BAD_FOV;
		}
	}
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
}

void	set_struct_light(t_mrt *mrt, t_token token, int *i_id_nbt)
{
	t_light	*light;

	light = lstlast_light(mrt->light);
	if (i_id_nbt[2] == 2)
	{
		if (ft_atovec3(light->lightpt, token.val) == ERROR_VEC)
			i_id_nbt[1] = ID_BAD_PT;
	}
	else if (i_id_nbt[2] == 3)
	{
		if (!can_atof(token.val))
			i_id_nbt[1] = ID_BAD_B_RAT;
		else
		{
			light->br = ft_atod(token.val);
			if (light->br < 0 || light->br > 1)
				i_id_nbt[1] = ID_BAD_B_RAT;
		}
	}
	else if (i_id_nbt[2] == 4)
	{
		if (ft_atorgb(light->rgb, token.val) == ERROR_RGB)
			i_id_nbt[1] = ID_BAD_RGB;
	}
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
}

void	set_struct_sphere(t_mrt *mrt, t_token token, int *i_id_nbt)
{
	t_obj	*obj;

	obj = lstlast_obj(mrt->obj);
	if (i_id_nbt[2] == 2)
	{
		if (ft_atovec3(obj->center, token.val) == ERROR_VEC)
			i_id_nbt[1] = ID_BAD_PT;
	}
	else if (i_id_nbt[2] == 3)
	{
		if (!can_atof(token.val))
			i_id_nbt[1] = ID_BAD_DIAM_S;
		else
		{
			obj->diam = ft_atod(token.val);
			if (obj->diam <= 0)
				i_id_nbt[1] = ID_BAD_DIAM_S;
		}
	}
	else if (i_id_nbt[2] == 4)
	{
		if (ft_atorgb(obj->rgb, token.val) == ERROR_RGB)
			i_id_nbt[1] = ID_BAD_RGB;
	}
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
}

void	set_struct_plane(t_mrt *mrt, t_token token, int *i_id_nbt)
{
	t_obj	*obj;
	int		err;

	obj = lstlast_obj(mrt->obj);
	if (i_id_nbt[2] == 2)
	{
		if (ft_atovec3(obj->center, token.val) == ERROR_VEC)
			i_id_nbt[1] = ID_BAD_PT;
	}
	else if (i_id_nbt[2] == 3)
	{
		err = ft_atovec3norm(obj->norm, token.val);
		if (err != NO_ERROR)
			i_id_nbt[1] = err;
	}
	else if (i_id_nbt[2] == 4)
	{
		if (ft_atorgb(obj->rgb, token.val) == ERROR_RGB)
			i_id_nbt[1] = ID_BAD_RGB;
	}
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
}
