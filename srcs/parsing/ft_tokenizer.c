/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:19:16 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/01 15:04:36 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_token	ft_tokenizer(t_state stm, char *str, int *i_id_nbt)
{
	t_token	token;

	if (stm == PARSE_IDENTIFIER)
		token.type = IDENTIFIER;
	else if (stm == PARSE_CONSTANT)
		token.type = CONSTANT;
	token.offset = i_id_nbt[0];
	while (!ft_iswhitespace(str[i_id_nbt[0]]) && str[i_id_nbt[0]])
		(i_id_nbt[0])++;
	token.val = ft_substr(str, token.offset, i_id_nbt[0] - token.offset);
	(i_id_nbt[2])++;
	return (token);
}
