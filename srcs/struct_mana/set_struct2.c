/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:08:39 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/07 11:42:25 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_struct_square(t_mrt *mrt, t_token token, int *i_id_nbt)
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
		assign_double_and_check_error(
			&obj->len, token.val, i_id_nbt, ID_BAD_LEN_SQ);
	else if (i_id_nbt[2] == 5)
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

void	set_struct_res(t_mrt *mrt, t_token token, int *i_id_nbt)
{
	if (i_id_nbt[2] == 2)
	{
		if (!can_atoi(token.val))
			i_id_nbt[1] = ID_BAD_RES;
		else
		{
			mrt->res->x = ft_atoi(token.val);
			if (mrt->res->x <= 0)
				i_id_nbt[1] = ID_BAD_RES;
		}
	}
	else if (i_id_nbt[2] == 3)
	{
		if (!can_atoi(token.val))
			i_id_nbt[1] = ID_BAD_RES;
		else
		{
			mrt->res->y = ft_atoi(token.val);
			if (mrt->res->y <= 0)
				i_id_nbt[1] = ID_BAD_RES;
		}
	}
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
}

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

void	set_struct_const(t_mrt *mrt, t_token token, int *i_id_nbt)
{
	if (i_id_nbt[1] == ID_RESOLUTION)
		set_struct_res(mrt, token, i_id_nbt);
	else if (i_id_nbt[1] == ID_AMBIENT_LIGHTINING)
		set_struct_ambiant(mrt, token, i_id_nbt);
	else if (i_id_nbt[1] == ID_CAMERA)
		set_struct_cam(mrt, token, i_id_nbt);
	else if (i_id_nbt[1] == ID_LIGHT)
		set_struct_light(mrt, token, i_id_nbt);
	else if (i_id_nbt[1] == ID_SPHERE)
		set_struct_sphere(mrt, token, i_id_nbt);
	else if (i_id_nbt[1] == ID_PLANE)
		set_struct_plane(mrt, token, i_id_nbt);
	else if (i_id_nbt[1] == ID_SQUARE)
		set_struct_square(mrt, token, i_id_nbt);
	else if (i_id_nbt[1] == ID_CYLINDER)
		set_struct_cylinder(mrt, token, i_id_nbt);
	else if (i_id_nbt[1] == ID_TRIANGLE)
		set_struct_triangle(mrt, token, i_id_nbt);
}
