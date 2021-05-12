/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:28:41 by lucille           #+#    #+#             */
/*   Updated: 2021/05/12 16:39:40 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	header_bmp(t_bmpheader *bh, t_mrt *mrt)
{
	ft_strcpy(bh->signature, "BM");
	bh->file_size = 14 + 40 + 3 * 8 * mrt->res->x * mrt->res->y;//?
	bh->reserved = 0;
	bh->data_offset = 14 + 40;//?
}

void	info_header_bmp(t_bmpinfoheader *bih, t_mrt *mrt)
{
	bih->size = 40;
	bih->width = mrt->res->x;
	bih->height = mrt->res->y;
	bih->planes = 1;
	bih->bitsperpix = 24;
	bih->compress = 0;//?
	bih->img_size = 3 * 8 * mrt->res->x * mrt->res->y;//?
	bih->res_h = 2000;//?
	bih->res_v = bih->res_h;//?
	bih->nb_color_used = 0;//?
	bih->nb_imp_color = 0;//?
}

void	pixel_data_bmp(t_bmp *bmp, int x, int y, t_rgb color)
{
	t_bmpinfoheader	*bih;
	int				pos;

	bih = &(bmp->bih);
	pos = ((bih->height - y - 1) * bih->width + x) * (bih->bitsperpix / 8);
	bmp->body[pos] = (char)fminf(color.b, 255);
	bmp->body[pos + 1] = (char)fminf(color.g, 255);
	bmp->body[pos + 2] = (char)fminf(color.r, 255);
	bmp->body[pos + 3] = 0x0;
}

int	write_bmp(t_bmp bmp, int fd)
{
	char	*body;
	int		size;

	if (write(fd, &(bmp.bh), sizeof(bmp.bh)) != sizeof(bmp.bh))
		return (ERROR_BMP);
	if (write(fd, &(bmp.bih), sizeof(bmp.bih)) != sizeof(bmp.bih))
		return (ERROR_BMP);
	body = bmp.body;
	size = 3 * bmp.bih.width * bmp.bih.height;
	if (write(fd, body, size) != size)
		return (ERROR_BMP);
	return (NO_ERROR);
}
