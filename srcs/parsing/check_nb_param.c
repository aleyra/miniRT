/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:18:13 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/01 13:28:41 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_nb_param(int *i_id_nbt)
{
	if (i_id_nbt[1] == ID_RESOLUTION && i_id_nbt[2] != 3)
		return (ERROR_NB_PARAM_R);
	if (i_id_nbt[1] == ID_AMBIENT_LIGHTINING && i_id_nbt[2] != 3)
		return (ERROR_NB_PARAM_A);
	if (i_id_nbt[1] == ID_CAMERA && i_id_nbt[2] != 4)
		return (ERROR_NB_PARAM_C);
	if (i_id_nbt[1] == ID_LIGHT && i_id_nbt[2] != 4)
		return (ERROR_NB_PARAM_L);
	if (i_id_nbt[1] == ID_SPHERE && i_id_nbt[2] != 4)
		return (ERROR_NB_PARAM_SP);
	if (i_id_nbt[1] == ID_PLANE && i_id_nbt[2] != 4)
		return (ERROR_NB_PARAM_PL);
	if (i_id_nbt[1] == ID_SQUARE && i_id_nbt[2] != 5)
		return (ERROR_NB_PARAM_SQ);
	if (i_id_nbt[1] == ID_CYLINDER && i_id_nbt[2] != 6)
		return (ERROR_NB_PARAM_CY);
	if (i_id_nbt[1] == ID_TRIANGLE && i_id_nbt[2] != 5)
		return (ERROR_NB_PARAM_TR);
	return (NO_ERROR);
}
