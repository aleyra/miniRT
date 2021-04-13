/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:27:16 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/13 09:32:38 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_cam_light(t_mrt *mrt)
{
	t_cam	*c;
	t_light	*l;

	c = mrt->cam;
	while (c)
	{
		printf("c\t");
		printf("%f,%f,%f\t", c->ptofview->x, c->ptofview->y, c->ptofview->z);
		printf("%f,%f,%f\t", c->dir->x, c->dir->y, c->dir->z);
		printf("%d\n", c->fov);
		c = c->next;
	}
	l = mrt->light;
	while (l)
	{
		printf("l\t");
		printf("%f,%f,%f", l->lightpt->x, l->lightpt->y, l->lightpt->z);
		printf("\t%f\t%d\n", l->br, l->rgb->i);
		l = l->next;
	}
}

static void	print_info_bonus_sq(t_obj *obj)
{
	printf("a(");
	printf("%f,%f,%f)\t", obj->a->x, obj->a->y, obj->a->z);
	printf("b(");
	printf("%f,%f,%f)\t", obj->b->x, obj->b->y, obj->b->z);
	printf("c(");
	printf("%f,%f,%f)\t", obj->c->x, obj->c->y, obj->c->z);
	printf("d(");
	printf("%f,%f,%f)\n", obj->d->x, obj->d->y, obj->d->z);
}

static void	print_obj2(t_obj *obj)
{
	if (obj->type == TYPE_SPHERE)
	{
		printf("sp\t");
		printf("%f,%f,%f\t", obj->center->x, obj->center->y, obj->center->z);
		printf("%f\t%d\n", obj->diam, obj->rgb->i);
	}
	else if (obj->type == TYPE_SQUARE)
	{
		printf("sq\t");
		printf("%f,%f,%f\t", obj->center->x, obj->center->y, obj->center->z);
		printf("%f,%f,%f\t", obj->norm->x, obj->norm->y, obj->norm->z);
		printf("%f\t%d\n", obj->len, obj->rgb->i);
		print_info_bonus_sq(obj);
	}
	else if (obj->type == TYPE_PLANE)
	{
		printf("pl\t");
		printf("%f,%f,%f\t", obj->center->x, obj->center->y, obj->center->z);
		printf("%f,%f,%f\t", obj->norm->x, obj->norm->y, obj->norm->z);
		printf("%d\n", obj->rgb->i);
	}
}

static void	print_obj1(t_obj *obj)
{
	if (obj->type == TYPE_CYLINDER)
	{
		printf("cy\t");
		printf("%f,%f,%f\t", obj->center->x, obj->center->y, obj->center->z);
		printf("%f,%f,%f\t", obj->norm->x, obj->norm->y, obj->norm->z);
		printf("%f\t%f\t%d\n", obj->diam, obj->height, obj->rgb->i);
	}
	else if (obj->type == TYPE_TRIANGLE)
	{
		printf("tr\t");
		printf("%f,%f,%f\t", obj->a->x, obj->a->y, obj->a->z);
		printf("%f,%f,%f\t", obj->b->x, obj->b->y, obj->b->z);
		printf("%f,%f,%f\t", obj->c->x, obj->c->y, obj->c->z);
		printf("%d\n", obj->rgb->i);
	}
	else
		print_obj2(obj);
}

void	print_mrt(t_mrt *mrt)
{
	t_obj	*obj;

	printf("R\t%d\t%d\n", mrt->res->x, mrt->res->y);
	printf("A\t%f\t%d\n\n", mrt->amb->ratio, mrt->amb->rgb->i);
	print_cam_light(mrt);
	printf("\n");
	obj = mrt->obj;
	while (obj)
	{
		print_obj1(obj);
		obj = obj->next;
	}
}
