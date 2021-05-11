/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:28:41 by lucille           #+#    #+#             */
/*   Updated: 2021/05/11 10:50:23 by lucille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	ft_file_header(t_mrt *mrt, int fd)
// {
// 	int						filesize;
// 	int						padding;
// 	static unsigned char	fileheader[] = {
// 		0, 0,
// 		0, 0, 0, 0,
// 		0, 0, 0, 0,
// 		0, 0, 0, 0,
// 	};

// 	padding = (4 - (mrt_>res->x * 3) % 4) % 4;
// 	filesize = 54 + (3 * mrt->res->x + padding) * mrt->res->y;
// 	fileheader[0] = (unsigned char)('B');
// 	fileheader[1] = (unsigned char)('M');
// 	fileheader[2] = (unsigned char)(filesize);
// 	fileheader[3] = (unsigned char)(filesize >> 8);
// 	fileheader[4] = (unsigned char)(filesize >> 16);
// 	fileheader[5] = (unsigned char)(filesize >> 24);
// 	fileheader[10] = (unsigned char)(54);
// 	write(fd, fileheader, 14);
// }

// void	ft_image_header(t_mrt *mrt, int fd)
// {
// 	static unsigned char	infoheader[] = {
// 		0, 0, 0, 0,
// 		0, 0, 0, 0,
// 		0, 0, 0, 0,
// 		0, 0, 0, 0,
// 		0, 0, 0, 0,
// 		0, 0, 0, 0,
// 		0, 0, 0, 0,
// 		0, 0, 0, 0,
// 		0, 0, 0, 0,
// 		0, 0, 0, 0,
// 	};

// 	infoheader[0] = (unsigned char)(40);
// 	infoheader[4] = (unsigned char)(mrt->res->x);
// 	infoheader[5] = (unsigned char)(mrt->res->x >> 8);
// 	infoheader[6] = (unsigned char)(mrt->res->x >> 16);
// 	infoheader[7] = (unsigned char)(mrt->res->x >> 24);
// 	infoheader[8] = (unsigned char)(mrt->res->y);
// 	infoheader[9] = (unsigned char)(mrt->res->y >> 8);
// 	infoheader[10] = (unsigned char)(mrt->res->y >> 16);
// 	infoheader[11] = (unsigned char)(mrt->res->y >> 24);
// 	infoheader[12] = (unsigned char)(1);
// 	infoheader[14] = (unsigned char)(24);
// 	write(fd, infoheader, 40);
// }

// void	ft_save_buffer(t_mrt *mrt, t_data img, int fd)
// {
// 	int						i;
// 	int						j;
// 	int						padding;
// 	static unsigned char	zero[3] = { 0, 0, 0};

// 	padding = (4 - (mrt->res->x * 3) % 4) % 4;
// 	i = mrt->res->y;
// 	while (i > 0)
// 	{
// 		i--;
// 		j = 0;
// 		while (j < mrt->res->x)
// 		{
// 			write(fd, img.addr[i * mrt->res->x + j], 3);
// 			j++;
// 		}
// 		if (padding > 0)
// 			write(fd, &zero, padding);
// 	}
// }