/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct_tr_cy_sp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:43:12 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/14 15:22:49 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	elseif_triangle(t_token token, int *i_id_nbt, t_obj *obj)
{
	if (i_id_nbt[2] == 4)
	{
		if (ft_atovec3(obj->c, token.val) == ERROR_VEC)
			i_id_nbt[1] = ID_BAD_PT;
		else if (!check_not_aligned(obj->a, obj->b, obj->b))
			i_id_nbt[1] = ID_BAD_PTS_T;
	}
	else if (i_id_nbt[2] == 5)
	{
		if (ft_atorgb(obj->rgb, token.val) == ERROR_RGB)
			i_id_nbt[1] = ID_BAD_RGB;
	}
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
}

void	set_struct_triangle(t_mrt *mrt, t_token token, int *i_id_nbt)
{
	t_obj	*obj;

	obj = lstlast_obj(mrt->obj);
	if (i_id_nbt[2] == 2)
	{
		if (ft_atovec3(obj->a, token.val) == ERROR_VEC)
			i_id_nbt[1] = ID_BAD_PT;
	}
	else if (i_id_nbt[2] == 3)
	{
		if (ft_atovec3(obj->b, token.val) == ERROR_VEC)
			i_id_nbt[1] = ID_BAD_PT;
	}
	else
		elseif_triangle(token, i_id_nbt, obj);
}

static void	elseif_cylinder(t_token token, int *i_id_nbt, t_obj *obj)
{
	if (i_id_nbt[2] == 4)
		assign_double_and_check_error(
			&obj->diam, token.val, i_id_nbt, ID_BAD_D_OR_H_C);
	else if (i_id_nbt[2] == 5)
		assign_double_and_check_error(
			&obj->height, token.val, i_id_nbt, ID_BAD_D_OR_H_C);
	else if (i_id_nbt[2] == 6)
	{
		if (ft_atorgb(obj->rgb, token.val) == ERROR_RGB)
			i_id_nbt[1] = ID_BAD_RGB;
	}
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
}

void	set_struct_cylinder(t_mrt *mrt, t_token token, int *i_id_nbt)
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
	else
		elseif_cylinder(token, i_id_nbt, obj);
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
		assign_double_and_check_error(
			&obj->diam, token.val, i_id_nbt, ID_BAD_DIAM_S);
	else if (i_id_nbt[2] == 4)
	{
		if (ft_atorgb(obj->rgb, token.val) == ERROR_RGB)
			i_id_nbt[1] = ID_BAD_RGB;
		init_quad_sp(obj);
	}
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
}
