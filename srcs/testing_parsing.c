/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:53:56 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/01 14:38:11 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char *av[])
{
	t_mrt	*mrt;
	int		i;
	int		fd;
	int		check_parsing;

	mrt = NULL;
	if (ac == 1)
		return (ft_display_error(ERROR_NO_PARAM));
	if (ac > 3)
		return (ft_display_error(ERROR_TOO_MANY_PARAM));
	i = ft_strlen(av[1]);
	if (i < 4 || (i > 3 && !(av[1][i - 3] == '.' && (
				av[1][i - 2] == 'r') && av[1][i - 1] == 't')))
		return (ft_display_error(ERROR_FILE_NOT_RT));
	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{	
		init_struct_mrt(&mrt);
		if (!mrt || !(mrt->res) || !(mrt->amb) || !(mrt->amb->rgb))
			return (ft_display_error(ERROR_MALLOC));
		check_parsing = ft_parsing(mrt, fd);
		if (check_parsing != 0)
			return (ft_display_error(check_parsing));
	}
	if (ac == 3)
	{
		if (ft_strcmp(av[2], "--save") != 0)
			return (ft_display_error(ERROR_IS_NOT_GOOD_SAVE));
		check_parsing = ft_parsing(mrt, fd);
		if (check_parsing != 0)
			return (ft_display_error(check_parsing));
	}
	return (0);
}
