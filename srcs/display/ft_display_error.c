/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:27:35 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/12 10:57:33 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	error_msg4(t_error cas)
{
	if (cas == ERROR_NB_PARAM_A)
		printf("The number of parameter for the ambient lightning is not good");
	else if (cas == ERROR_NB_PARAM_C)
		printf("The number of parameter for a camera is not good");
	else if (cas == ERROR_NB_PARAM_L)
		printf("The number of parameter for a light is not good");
	else if (cas == ERROR_NB_PARAM_SP)
		printf("The number of parameter for a sphere is not good");
	else if (cas == ERROR_NB_PARAM_PL)
		printf("The number of parameter for a plane is not good");
	else if (cas == ERROR_NB_PARAM_SQ)
		printf("The number of parameter for a square is not good");
	else if (cas == ERROR_NB_PARAM_CY)
		printf("The number of parameter for a cylinder is not good");
	else if (cas == ERROR_NB_PARAM_TR)
		printf("The number of parameter for a triangle is not good");
	else if (cas == ERROR_MALLOC)
		printf("MALLOC error");
	else if (cas == ERROR_NO_CAM)
		printf("You need to set at least one camera\n");
	else if (cas == ERROR_BMP)
		printf("The bmp file failed\n");
	printf("error to define");
}

static void	error_msg3(t_error cas)
{
	if (cas == ERROR_VECTOR_N)
	{
		printf("At least, one of the coordinate of a 3d normalized vector ");
		printf("is not in [-1;1]");
	}
	else if (cas == ERROR_FOV)
		printf("FOV is not a integer in [0,180]");
	else if (cas == ERROR_BRIGHTNESS_RATIO)
	{
		printf("The light brightness ratio of one of the light spot ");
		printf("is not in [0.0,1.0]");
	}
	else if (cas == ERROR_D_SP)
		printf("The diameter of the sphere is not positive");
	else if (cas == ERROR_S_SQ)
		printf("The side size of the square is not positive");
	else if (cas == ERROR_D_OR_H_CY)
		printf("The diameter or the heigh of the cylinder is not positive");
	else if (cas == ERROR_PTS_ALIGNED_TR)
		printf("All 3 points of the triangle are aligned");
	else if (cas == ERROR_NB_PARAM_R)
		printf("The number of parameter for the resolution is not good");
	else
		error_msg4(cas);
}

static void	error_msg2(t_error cas)
{
	if (cas == ERROR_PARSING_CHAR)
		printf("Character unlikely found in your .rt file. Please review it");
	else if (cas == ERROR_PARSING_PARAM || cas == ERROR_PARSING_CHAR_BIS)
	{
		printf("In at least one of the line of your .rt file,");
		printf(" there's too many parameters");
	}
	else if (cas == ERROR_RGB)
		printf("One of the rgb's parameter is wrong");
	else if (cas == ERROR_RES)
	{
		printf("At least one of the parameters of the ");
		printf("resolution is not a positive int");
	}
	else if (cas == ERROR_AMBIENT_RATIO)
		printf("The ambient lighting ratio is not in [0,1]");
	else if (cas == ERROR_VEC)
	{
		printf("One coordinate of a vector/point is not ");
		printf("a float or there isn't 3 coordinates or this vector is 0");
	}
	else
		error_msg3(cas);
}

static void	error_msg1(t_error cas)
{
	printf("Error\n");
	if (cas == NO_ERROR)
		printf("No Error");
	else if (cas == ERROR_FILE_NOT_RT || cas == ERROR_GNL)
		printf("This is not a file .rt");
	else if (cas == ERROR_IS_NOT_GOOD_SAVE)
		printf("The 2nd parameter is not \"--save\"");
	else if (cas == ERROR_NO_PARAM)
	{
		printf("Program launch without any parameter\n");
		printf("Please add a .rt file as an parameter");
	}
	else if (cas == ERROR_TOO_MANY_PARAM)
	{
		printf("Too many parameters\nNeeds max 2 parameters :");
		printf(" a .rt file and \"--save\"");
	}
	else if (cas == ERROR_IDENTIFIER)
	{
		printf("The file contains an identifier ");
		printf("which does not match the subject");
	}
	else
		error_msg2(cas);
}

int	ft_display_error(int cas, t_mrt *mrt)
{
	if (cas != NO_ERROR)
	{
		error_msg1(cas);
		printf("\n");
	}
	if (mrt)
		free_mrt(mrt);
	return (0);
}
