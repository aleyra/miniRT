/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:42:16 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/03 15:08:46 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int ac, char *av[])
{
	char	***tab2d;
	int		i;

	*tab2d = split_fd_to_tabline(av[0]);
	while (*tab2d[i])
	{
		printf("%d\t%s\n", i, *tab2d[i]);
		i++;
	}
	return (0);
}
