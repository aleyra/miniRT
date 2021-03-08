/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:55:19 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/08 15:23:58 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_error {
	ERROR_OK,
	ERROR_FILE_NOT_RT,
	ERROR2
}	t_error;

char	*g_error_msg[] = {
	[ERROR_OK] = "No Error",
	[ERROR_FILE_NOT_RT] = "The file is not a .rt",
};

#endif
