/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:17:09 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/13 09:09:58 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/* ************************************************************************** */
/* in the following fcts, i_id_nbt is a table of 3 int for 					  */
/* i_id_nbt[0] = i is a compter of char for line 							  */
/* i_id_nbt[1] = type of identifier which tells if the line id about R, a,... */
/* it serves also to mark error 											  */
/* i_id_nbt[2] = give the nb of token created until here from this line 	  */
/* i_id_nbt[3] = gnl = return of gnl									 	  */
/* ************************************************************************** */

static int	end_of_while(int *i_id_nbt, char **line, int fd, int *gnl)
{
	free(*line);
	i_id_nbt[2] = check_nb_param(i_id_nbt);
	if (i_id_nbt[2] != 0)
		return (i_id_nbt[2]);
	i_id_nbt[0] = 0;
	i_id_nbt[1] = 0;
	*gnl = get_next_line(fd, line);
	return (NO_ERROR);
}

static t_state	init_parsing(char **line, int *gnl, int fd, int *i_id_nbt)
{
	*line = NULL;
	*gnl = get_next_line(fd, line);
	i_id_nbt[2] = 0;
	i_id_nbt[0] = 0;
	i_id_nbt[1] = 0;
	return (0);
}

static int	end_of_parsing(char **line, int gnl)
{
	if (*line != NULL)
		free(*line);
	if (gnl == -1)
		return (ERROR_GNL);
	return (NO_ERROR);
}

static int	second_while(t_state *stm, int *i_id_nbt, char **line, t_mrt *mrt)
{
	t_token	token;

	*stm = ft_change_state(*stm, *line, &i_id_nbt[0], i_id_nbt[3]);
	if (*stm == PARSE_ERROR)
	{
		free(*line);
		return (ERROR_PARSING_CHAR);
	}
	token = ft_tokenizer(*stm, *line, i_id_nbt);
	if ((token.type == IDENTIFIER && i_id_nbt[2] != 1) || (
			token.type == CONSTANT && i_id_nbt[2] == 1))
	{
		free(token.val);
		free(*line);
		return (ERROR_PARSING_CHAR);
	}
	set_struct(mrt, token, i_id_nbt);
	if (i_id_nbt[1] >= ID_ERROR)
	{
		free(token.val);
		free(*line);
		return (i_id_nbt[1]);
	}
	free(token.val);
	return (0);
}

int	ft_parsing(t_mrt *mrt, int fd)
{
	char	*line;
	t_state	stm;
	int		i_id_nbt[4];
	int		temp;

	stm = init_parsing(&line, &i_id_nbt[3], fd, i_id_nbt);
	while (i_id_nbt[3] > 0)
	{
		 while (line[i_id_nbt[0]])
		{
			temp = second_while(&stm, i_id_nbt, &line, mrt);
			if (temp != 0)
				return (temp);
		}
		if (end_of_while(i_id_nbt, &line, fd, &i_id_nbt[3]) != NO_ERROR)
			return (i_id_nbt[2]);
	}
	return (end_of_parsing(&line, i_id_nbt[3]));
}
