/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct_sq_pl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:08:39 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/29 13:33:40 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	elseif_square(t_token token, int *i_id_nbt, t_obj *o)
{
	if (i_id_nbt[2] == 4)
		assign_double_and_check_error(
			&o->len, token.val, i_id_nbt, ID_BAD_LEN_SQ);
	else if (i_id_nbt[2] == 5)
	{
		init_quad_pl(o);
		complete_sq(o);
		if (init_color_initial(o->rgb, token.val) == ERROR_RGB)
			i_id_nbt[1] = ID_BAD_RGB;
	}
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
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
	else
		elseif_square(token, i_id_nbt, obj);
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
		init_quad_pl(obj);
	}
	else if (i_id_nbt[2] == 4)
	{
		if (init_color_initial(obj->rgb, token.val) == ERROR_RGB)
			i_id_nbt[1] = ID_BAD_RGB;
	}
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
}
