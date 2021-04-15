/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:55:26 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/15 16:11:10 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* ************************************************************************** */
/* in the following fct,													  */
/* other is a table of 2 int for 											  */
/* other[0] = use for ft_strlen & fd for gnl in ft_parsing				 	  */
/* other[1] = check_parsing for the return of ft_parsing and cas in disp_error*/
/* ************************************************************************** */
static int	init_main(int ac, char *av[], t_mrt	**mrt)
{
	int	other[2];

	if (ac == 1)
		return (ERROR_NO_PARAM);
	if (ac > 3)
		return (ERROR_TOO_MANY_PARAM);
	other[0] = ft_strlen(av[1]);
	if (other[0] < 4 || (other[0] > 3 && !(av[1][other[0] - 3] == '.' && (
				av[1][other[0] - 2] == 'r') && av[1][other[0] - 1] == 't')))
		return (ERROR_FILE_NOT_RT);
	if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
		if (ft_strcmp(av[2], "--save") != 0)
			return (ERROR_IS_NOT_GOOD_SAVE);
	other[0] = open(av[1], O_RDONLY);
	init_struct_mrt(mrt);
	if (!*mrt || !((*mrt)->res) || !((*mrt)->amb) || !((*mrt)->amb->rgb))
		return (ERROR_MALLOC);
	other[1] = ft_parsing(*mrt, other[0]);
	print_mrt(*mrt);//
	close(other[0]);
	if (other[1] != 0)
		return (other[1]);
	return (NO_ERROR);
}

/* ************************************************************************** */
/* in the following fct, ijo is a table of 3 int for 						  */
/* ijo[0] = i is a compter for x /!\ origin is up left						  */
/* ijo[1] = j is a compter for y				 							  */
/* ijo[2] = other								 							  */
/* ************************************************************************** */
int	main(int ac, char *av[])
{
	t_mrt	*mrt;
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	int		ijo[3];

	mrt = NULL;
	ijo[2] = init_main(ac, av, &mrt);
	if (ijo[2] != NO_ERROR)
		return (ft_display_error(ijo[2], mrt));
	mlx = mlx_init();
	if (ac == 2)
	{
		mlx_win = mlx_new_window(mlx, mrt->res->x, mrt->res->y, "miniRT");
		img.img = mlx_new_image(mlx, mrt->res->x, mrt->res->y);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pix, &img.line_len,
				&img.endian);
		printf("on lance la sauce\n");
		my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
		ray_shooter(&img, mrt);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}
	if (ac == 3)//creation d'un bmp
	{
		printf("a faire\n");//
	}
	return (ft_display_error(NO_ERROR, mrt));
}
