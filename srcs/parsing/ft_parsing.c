/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:17:09 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/03 14:49:18 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	***file_to_tab2d(int fd, char ***tab2d)
{
	int i;

	*tab2d = split_fd_to_tabline(fd);
	i = 0;
	while (*tab2d[i])
	{
		*tab2d[i] = ft_split(*tab2d[i], ' ');
		i++;
	}
	return (tab2d);
}

/*void		parsing_to_struct(char ***tab2d, t_mrt *mrt)
{
	
}*/
