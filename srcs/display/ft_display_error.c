/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:27:35 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/03 13:15:53 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_error_type_message_n1(int cas)
{
	if (cas == 7)
		printf("The diameter of the sphere is not positive\n");
	else if (cas == 8)
		printf("The side size of the square is not positive\n");
	else if (cas == 9)
		printf("The diameter or the heigh of the cylinder is not positive\n");
	else if (cas == 10)
		printf("All 3 points of the triangle are aligned\n");
}

static void	print_error_type_message(int cas)
{
	if (cas == 0)
		printf("The file is not a .rt\n");
	else if (cas == 1)
		printf("The 2nd parameter is not \"--save\"\n");
	else if (cas == 2)
		printf("The ambient lighting ratio is not in [0,1]\n");
	else if (cas == 3)
		printf("At least, one of RGB parameter is not a integer in [0,255]\n");
	else if (cas == 4)
	{
		printf("At least, one of the coordinate of ");
		printf("a 3d normalized vector is not in [-1;1]\n");
	}
	else if (cas == 5)
		printf("FOV is not a integer in [0,180]\n");
	else if (cas == 6)
	{
		printf("The light brightness ratio of one of the ");
		printf("light spot is not in [0.0,1.0]\n");
	}
	else
		print_error_type_message_n1(cas);
}

int			ft_display_error(int cas)
{
	printf("Error\n");
	print_error_type_message(cas);
	//call ft_free_all_to_free
	return (-1);
}