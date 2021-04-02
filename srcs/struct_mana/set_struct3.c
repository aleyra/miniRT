/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:16:50 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/02 11:06:26 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	assign_double_and_check_error(
	double *d, char *str, int *err, int nb_err)
{
	if (!can_atod(str))
		err[1] = nb_err;
	else
	{
		*d = ft_atod(str);
		if (*d <= 0)
			err[1] = nb_err;
	}
}

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
	else if (i_id_nbt[2] == 4)
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
	else if (i_id_nbt[2] == 4)
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
