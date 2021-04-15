/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_starting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:11:01 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/15 15:40:15 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	int		i;
	int		j;
	int color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World !");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(
			img.img, &img.bits_per_pix, &img.line_len, &img.endian);
	i = 10;
	color = 0x00000000;
	while (i < 1010)
	{
		j = 30;
		while (j < 1030)
		{
			if (j % 10 == 0)
				color++;
			my_mlx_pixel_put(&img, i, j, color);
			j++;
		}
		i++;
	}
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
