/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct_base_R_A.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 08:31:49 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/19 11:26:08 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		if (init_color_initial(mrt->amb->rgb, token.val) == ERROR_RGB)
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
