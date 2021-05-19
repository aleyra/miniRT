/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:22:17 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/19 15:07:53 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, t_rgb color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * data->bits_per_pix / 8);
	*(unsigned int *) dst = color.i;
	if (x == 1440 && y == 530)
	{
		print_rgb(&color);
		printf("i = %d\n", color.i);
	}
}
