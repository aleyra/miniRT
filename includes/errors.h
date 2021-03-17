/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:55:19 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/11 13:06:00 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_error {
	NO_ERROR,
	ERROR_FILE_NOT_RT,
	ERROR_IS_NOT_GOOD_SAVE,
	ERROR_AMBIENT_RATIO,
	ERROR_RGB,
	ERROR_VECTOR_N,
	ERROR_FOV,
	ERROR_BRIGHTNESS_RATIO,
	ERROR_D_SP,
	ERROR_S_SQ,
	ERROR_D_OR_H_CY,
	ERROR_PTS_ALIGNED_TR,
	ERROR_NO_PARAM,
	ERROR_TOO_MANY_PARAM
}	t_error;

char	*g_error_msg[] = {
	[NO_ERROR] = "No Error",
	[ERROR_FILE_NOT_RT] = "The file is not a .rt",
	[ERROR_IS_NOT_GOOD_SAVE] = "The 2nd parameter is not \"--save\"",
	[ERROR_AMBIENT_RATIO] = "The ambient lighting ratio is not in [0,1]",
	[ERROR_RGB] = "At least, one of RGB parameter is not a integer in [0,255]",
	[ERROR_VECTOR_N] = "At least, one of the coordinate of a 3d normalized \
vector is not in [-1;1]",
	[ERROR_FOV] = "FOV is not a integer in [0,180]",
	[ERROR_BRIGHTNESS_RATIO] = "The light brightness ratio of one of the \
light spot is not in [0.0,1.0]",
	[ERROR_D_SP] = "The diameter of the sphere is not positive",
	[ERROR_S_SQ] = "The side size of the square is not positive",
	[ERROR_D_OR_H_CY] = "The diameter or the heigh of the cylinder \
is not positive",
	[ERROR_PTS_ALIGNED_TR] = "All 3 points of the triangle are aligned",
	[ERROR_NO_PARAM] = "Program launch without any parameter\nPlease \
add a .rt file as an parameter",
	[ERROR_TOO_MANY_PARAM] = "Too many parameters\n\
Needs max 2 parameters : a .rt file and \"--save\""
};

int	ft_display_error(int cas);

#endif
