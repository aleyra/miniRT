/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:27:16 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/29 13:36:22 by lburnet          ###   ########lyon.fr   */
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
		printf("%f\n", c->fovr);
		c = c->next;
	}
	l = mrt->light;
	while (l)
	{
		printf("l\t");
		printf("%f,%f,%f", l->lightpt->x, l->lightpt->y, l->lightpt->z);
		printf("\t%f\t%d,%d,%d\n", l->br, l->rgb->r, l->rgb->g, l->rgb->b);
		l = l->next;
	}
}

static void	print_quadric_coeff(t_obj *obj)
{
	printf("Quadric coeff : A = %f\t", obj->quad->a);
	printf("B = %f\t", obj->quad->b);
	printf("C = %f\t", obj->quad->c);
	printf("D = %f\t", obj->quad->d);
	printf("E = %f\t", obj->quad->e);
	printf("F = %f\t", obj->quad->f);
	printf("G = %f\t", obj->quad->g);
	printf("H = %f\t", obj->quad->h);
	printf("I = %f\t", obj->quad->i);
	printf("J = %f\n", obj->quad->j);
}

static void	print_obj2(t_obj *ob)
{
	if (ob->type == TYPE_SPHERE)
	{
		printf("sp\t");
		printf("%f,%f,%f\t", ob->center->x, ob->center->y, ob->center->z);
		printf("%f\t%d,%d,%d\n", ob->diam, ob->rgb->r, ob->rgb->g, ob->rgb->b);
	}
	else if (ob->type == TYPE_SQUARE)
	{
		printf("sq\t");
		printf("%f,%f,%f\t", ob->center->x, ob->center->y, ob->center->z);
		printf("%f,%f,%f\t", ob->norm->x, ob->norm->y, ob->norm->z);
		printf("%f\t%d,%d,%d\n", ob->len, ob->rgb->r, ob->rgb->g, ob->rgb->b);
		print_corner_sq(ob);
	}
	else if (ob->type == TYPE_PLANE)
	{
		printf("pl\t");
		printf("%f,%f,%f\t", ob->center->x, ob->center->y, ob->center->z);
		printf("%f,%f,%f\t", ob->norm->x, ob->norm->y, ob->norm->z);
		printf("%d,%d,%d\n", ob->rgb->r, ob->rgb->g, ob->rgb->b);
	}
}

static void	print_obj1(t_obj *ob)
{
	if (ob->type == TYPE_CYLINDER)
	{
		printf("cy\t");
		printf("%f,%f,%f\t", ob->center->x, ob->center->y, ob->center->z);
		printf("%f,%f,%f\t", ob->norm->x, ob->norm->y, ob->norm->z);
		printf("%f\t%f\t", ob->diam, ob->height);
		printf("%d,%d,%d\n", ob->rgb->r, ob->rgb->g, ob->rgb->b);
	}
	else if (ob->type == TYPE_TRIANGLE)
	{
		printf("tr\t");
		printf("%f,%f,%f\t", ob->a->x, ob->a->y, ob->a->z);
		printf("%f,%f,%f\t", ob->b->x, ob->b->y, ob->b->z);
		printf("%f,%f,%f\t", ob->c->x, ob->c->y, ob->c->z);
		printf("%d,%d,%d\n", ob->rgb->r, ob->rgb->g, ob->rgb->b);
	}
	else
		print_obj2(ob);
}

void	print_mrt(t_mrt *mrt)
{
	t_obj	*obj;

	printf("R\t%d\t%d\n", mrt->res->x, mrt->res->y);
	printf("A\t%f\t", mrt->amb->ratio);
	printf("%d,%d,%d\n\n", mrt->amb->rgb->r, mrt->amb->rgb->g, mrt->amb->rgb->b);
	print_cam_light(mrt);
	printf("\n");
	obj = mrt->obj;
	while (obj)
	{
		print_obj1(obj);
		print_quadric_coeff(obj);
		obj = obj->next;
	}
}
