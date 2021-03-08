/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:53:56 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/08 15:21:50 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char *av[])
{
	char	***tab2d;
	int		i;

	if (ac == 1)
		return (ft_display_error(11));
	if (ac == 2)
	{
		i = strlen(av[1]);
		if (i < 4 ||(i > 3 && !(av[i - 2] == '.' && av[i - 1] == 'r' && av[i] == 't')))
			return (ft_display_error(0));
		i = 0;
		*tab2d = split_fd_to_tabline(av[0]);
		while (*tab2d[i])
		{
			printf("%d\t%s\n", i, *tab2d[i]);
			i++;
		}
	}
	if (ac == 3)
	{
		i = strlen(av[1]);
		if (i < 4 ||(i > 3 && !(av[i - 2] == '.' && av[i - 1] == 'r' && av[i] == 't')))
			return (ft_display_error(0));
		if (ft_strcmp(av[2], "--save") != 0)
			return (ft_display_error(1));
	}
	if (ac > 3)
		return (ft_display_error(12));
	return (0);
}
