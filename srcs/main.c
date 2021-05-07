/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:55:26 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/07 17:04:38 by lburnet          ###   ########lyon.fr   */
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

void	main_ac_2(void *mlx, t_mrt *mrt)
{
	t_vars	v;
	t_data	img;

	v.mlx = mlx;
	v.mrt = mrt;
	v.cam = mrt->cam;
	v.win = mlx_new_window(mlx, mrt->res->x, mrt->res->y, "miniRT");
	img.img = mlx_new_image(mlx, mrt->res->x, mrt->res->y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pix, &img.line_len,
			&img.endian);
	printf("on lance la sauce\n");
	v.img = &img;
	ray_shooter(&img, mrt, v.cam);
	mlx_put_image_to_window(mlx, v.win, img.img, 0, 0);
	mlx_hook(v.win, 2, 1L<<0, interact, &v);
	mlx_loop(mlx);
}

int	main(int ac, char *av[])
{
	t_mrt	*mrt;
	void	*mlx;
	int		err;

	mrt = NULL;
	err = init_main(ac, av, &mrt);
	if (err != NO_ERROR)
		return (ft_display_error(err, mrt));
	mlx = mlx_init();
	if (ac == 2)
	{
		main_ac_2(mlx, mrt);
	}
	if (ac == 3)//creation d'un bmp
	{
		printf("a faire\n");//
	}
	return (ft_display_error(NO_ERROR, mrt));
}
