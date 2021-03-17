/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:27:35 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/10 09:57:16 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "errors.h"

int	ft_display_error(int cas)
{
	printf("Error\n");
	if (cas != NO_ERROR)
		printf("%s\n", g_error_msg[cas]);
	//call ft_free_all_to_free
	return (-1);
}
