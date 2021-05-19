/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:28:41 by lucille           #+#    #+#             */
/*   Updated: 2021/05/19 15:41:12 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	file_header_bmp(t_bmpfileheader *bh, t_mrt *mrt)
{
	ft_strcpy(bh->signature, "BM");
	bh->file_size = sizeof(t_bmpheader) + 32 * mrt->res->x * mrt->res->y;
	bh->reserved = 0;
	bh->data_offset = sizeof(t_bmpheader);
}

static void	info_header_bmp(t_bmpinfoheader *bih, t_mrt *mrt)
{
	bih->size = sizeof(t_bmpinfoheader);
	bih->width = mrt->res->x;
	bih->height = mrt->res->y;
	bih->planes = 1;
	bih->bitsperpix = 32;
	bih->compress = 0;
	bih->img_size = 32 * mrt->res->x * mrt->res->y;
	bih->res_h = 0;
	bih->res_v = 0;
	bih->nb_color_used = 0;
	bih->nb_imp_color = 0;
}

void	header_bmp(t_bmp *bmp, t_mrt *mrt)
{
	file_header_bmp(&bmp->h.bfh, mrt);
	info_header_bmp(&bmp->h.bih, mrt);
}

void	pixel_data_bmp(t_bmp *bmp, int x, int y, t_rgb color)
{
	t_bmpinfoheader	*bih;
	int				pos;

	bih = &(bmp->h.bih);
	pos = ((bih->height - y - 1) * bih->width + x) * (bih->bitsperpix / 8);
	bmp->body[pos] = (char)color.b;
	bmp->body[pos + 1] = (char)color.g;
	bmp->body[pos + 2] = (char)color.r;
	bmp->body[pos + 3] = 0x0;
}

int	write_bmp(t_bmp bmp, int fd)
{
	if (write(fd, &(bmp.h.bfh), sizeof(bmp.h.bfh)) != sizeof(bmp.h.bfh))
		return (ERROR_BMP);
	if (write(fd, &(bmp.h.bih), sizeof(bmp.h.bih)) != sizeof(bmp.h.bih))
		return (ERROR_BMP);
	if (write(fd, bmp.body, bmp.h.bih.img_size) != bmp.h.bih.img_size)
		return (ERROR_BMP);
	return (NO_ERROR);
}
