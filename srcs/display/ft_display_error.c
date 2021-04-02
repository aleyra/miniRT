/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:27:35 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/01 13:58:41 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*error_msg(t_error cas)
{
	if (cas == NO_ERROR)
		return ("No Error");
	if (cas == ERROR_FILE_NOT_RT || cas == ERROR_GNL)
		return ("This is not a file .rt");
	if (cas == ERROR_IS_NOT_GOOD_SAVE)
		return ("The 2nd parameter is not \"--save\"");
	if (cas == ERROR_NO_PARAM)
		return ("Program launch without any parameter\nPlease add a .rt file as an parameter");
	if (cas == ERROR_TOO_MANY_PARAM)
		return ("Too many parameters\nNeeds max 2 parameters : a .rt file and \"--save\"");
	if (cas == ERROR_IDENTIFIER)
		return ("The file contains an identifier which does not match the subject");
	if (cas == ERROR_PARSING_CHAR)
		return ("Character unlikely found in your .rt file. Please review it");
	if (cas == ERROR_PARSING_PARAM)
		return ("In at least one of the line of your .rt file, there's too many parameters");
	if (cas == ERROR_RGB)
		return ("One of the rgb's parameter is wrong");
	if (cas == ERROR_RES)
		return ("At least one of the parameters of the resolution is not a positive int");
	if (cas == ERROR_AMBIENT_RATIO)
		return ("The ambient lighting ratio is not in [0,1]");
	if (cas == ERROR_VEC)
		return ("One coordinate of a vector/point is not a float or there isn't 3 coordinates");
	if (cas == ERROR_VECTOR_N)
		return ("At least, one of the coordinate of a 3d normalized vector is not in [-1;1]");
	if (cas == ERROR_FOV)
		return ("FOV is not a integer in [0,180]");
	if (cas == ERROR_BRIGHTNESS_RATIO)
		return ("The light brightness ratio of one of the light spot is not in [0.0,1.0]");
	if (cas == ERROR_D_SP)
		return ("The diameter of the sphere is not positive");
	if (cas == ERROR_S_SQ)
		return ("The side size of the square is not positive");
	if (cas == ERROR_D_OR_H_CY)
		return ("The diameter or the heigh of the cylinder is not positive");
	if (cas == ERROR_PTS_ALIGNED_TR)
		return ("All 3 points of the triangle are aligned");
	if (cas == ERROR_NB_PARAM_R)
		return ("The number of parameter for the resolution is not good");
	if (cas == ERROR_NB_PARAM_A)
		return ("The number of parameter for the ambient lightning is not good");
	if (cas == ERROR_NB_PARAM_C)
		return ("The number of parameter for a camera is not good");
	if (cas == ERROR_NB_PARAM_L)
		return ("The number of parameter for a light is not good");
	if (cas == ERROR_NB_PARAM_SP)
		return ("The number of parameter for a sphere is not good");
	if (cas == ERROR_NB_PARAM_PL)
		return ("The number of parameter for a plane is not good");
	if (cas == ERROR_NB_PARAM_SQ)
		return ("The number of parameter for a square is not good");
	if (cas == ERROR_NB_PARAM_CY)
		return ("The number of parameter for a cylinder is not good");
	if (cas == ERROR_NB_PARAM_TR)
		return ("The number of parameter for a triangle is not good");
	if (cas == ERROR_MALLOC)
		return ("MALLOC error");
	return ("error to define");
}

int	ft_display_error(int cas)
{
	printf("Error\n");
	if (cas != NO_ERROR)
		printf("%s\n", error_msg(cas));
	//call ft_free_all_to_free
	return (-1);
}
