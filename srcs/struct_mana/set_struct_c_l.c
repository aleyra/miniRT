/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct_c_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:16:50 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/14 14:58:02 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	assign_double_and_check_error(
	double *d, char *str, int *err, int nb_err)
{
	if (!can_atof(str))
		err[1] = nb_err;
	else
	{
		*d = ft_atod(str);
		if (*d <= 0)
			err[1] = nb_err;
	}
}

static void	assign_fov_cam(float *rad, char *str, int *err, int nb_err)
{
	int	i;

	if (!can_atoi(str))
		err[1] = nb_err;
	else
	{
		i = ft_atoi(str);
		if (i < 0 || i > 180)
			err[1] = nb_err;
		*rad = deg_to_rad(i);
	}
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
		assign_fov_cam(&cam->fovr, token.val, i_id_nbt, ID_BAD_FOV);
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
}

static void	assign_double_light(double *d, char *str, int *err, int nb_err)
{
	if (!can_atof(str))
		err[1] = nb_err;
	else
	{
		*d = ft_atod(str);
		if (*d < 0 || *d > 1)
			err[1] = nb_err;
	}
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
		assign_double_light(&light->br, token.val, i_id_nbt, ID_BAD_B_RAT);
	else if (i_id_nbt[2] == 4)
	{
		if (ft_atorgb(light->rgb, token.val) == ERROR_RGB)
			i_id_nbt[1] = ID_BAD_RGB;
	}
	else
		i_id_nbt[1] = ID_TOO_MANY_PARAM;
}
