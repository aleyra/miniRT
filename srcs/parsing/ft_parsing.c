/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:17:09 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/01 15:09:20 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/* ************************************************************************** */
/* int the following fct, i_id_nbt is a table of 3 int for 					  */
/* i_id_nbt[0] = i is a compter of char for line 							  */
/* i_id_nbt[1] = type of identifier which tells if the line id about R, a,... */
/* it serves also to mark error 											  */
/* i_id_nbt[2] = give the nb of token created until here from this line 	  */
/* ************************************************************************** */
int	ft_parsing(t_mrt *mrt, int fd)
{
	char	*line;
	int		gnl;
	t_state	stm;
	int		i_id_nbt[3];
	t_token	token;

	stm = 0;
	line = NULL;
	gnl = get_next_line(fd, &line);
	(void) *mrt;
	i_id_nbt[2] = 0;
	while (gnl > 0)
	{
		i_id_nbt[0] = 0;
		i_id_nbt[1] = 0;
		printf("line = %s\n", line);//
		 while (line[i_id_nbt[0]])
		{
			stm = ft_change_state(stm, line, &i_id_nbt[0], gnl);
			if (stm == PARSE_ERROR)
			{
				free(line);
				return (ERROR_PARSING_CHAR);
			}
			token = ft_tokenizer(stm, line, i_id_nbt);
			printf("stm = %d\toffset = %d\ttype = %d\t val = %s\ti_id_nbt[2] = %d\n", stm, token.offset, token.type, token.val, i_id_nbt[2]);//
			if ((token.type == IDENTIFIER && i_id_nbt[2] != 1) || (
					token.type == CONSTANT && i_id_nbt[2] == 1))
			{
				free(token.val);
				free(line);
				return (ERROR_PARSING_CHAR);
			}
			set_struct(mrt, token, i_id_nbt);
			if (i_id_nbt[1] >= ID_ERROR)
			{
				free(token.val);
				free(line);
				return (i_id_nbt[1]);
			}
			free(token.val);
		}
		free(line);
		i_id_nbt[2] = check_nb_param(i_id_nbt);
		if (i_id_nbt[2] != 0)
			return (i_id_nbt[2]);
		gnl = get_next_line(fd, &line);
	}
	if (line != NULL)
		free(line);
	if (gnl == -1)
		return (ERROR_GNL);
	return (NO_ERROR);
}
