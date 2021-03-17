/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:37:46 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/17 15:18:42 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	dst;

	dst = data->addr + (y * data->line_len + x * data->bits_per_pix * 0.125f);//mieux /8 ?
	*(unsigned int *)dst = color;
}

int	main(int ac, char *av[])
{
	void	*mlx;
	//void    *mlx_win;
	t_data	img;
	s_mrt	mrt;//struct contenant le parsing
	//int	i;
	//int	j;

	//parsing a faire de av[1]
	mlx = mlx_init();
	//if (ac == 2)//on affiche une fenetre
	//{
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//mlx_win = mlx_new_window(mlx, mrt.r.x, mrt.r.y, "miniRT");
	//mlx_loop(mlx);
	//}
	//if (ac == 3)
	//{
	img.img = mlx_new_image(mlx, mrt.r.x, mrt.r.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pix, &img.line_len,
			&img.endian);
	// i = 0;
	// while (i < mrt.r.x)
	// {
	// 	j = 0;
	// 	while (j < mrt.r.x)
	// 	{
	// 		//si le vec rencontre un obj
	// 		//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);// avec a le place de 5, 5 le pt de rencontre suivi de la couleur de l'obj
	// 		//sinon
	// 		my_mlx_pixel_put(&img, i, j, mrt.a.rgb.i);
	// 		j++;
	// 	}
	// 	i++;
	// }
	//}
	return (0);
}
