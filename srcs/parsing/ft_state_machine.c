/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_machine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:56:27 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/01 15:00:25 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_change_state(t_state stm, char *str, int *i, int gnl)
{
	if (gnl == 0)
		return (END_DATA);
	if (stm == FIND_DATA)
	{
		while (ft_iswhitespace(str[*i]))
			(*i)++;
		stm = FIND_TOKEN;
	}
	if (stm != FIND_DATA && stm != FIND_TOKEN && stm != END_DATA)
		stm = FIND_TOKEN;
	if (stm == FIND_TOKEN)
	{
		while (ft_iswhitespace(str[*i]))
			(*i)++;
		if (ft_isalpha(str[*i]))
			return (PARSE_IDENTIFIER);
		else if (ft_isdigit(str[*i]) || str[*i] == '-')
			return (PARSE_CONSTANT);
		else
			return (PARSE_ERROR);
	}
	return (PARSE_ERROR);
}
