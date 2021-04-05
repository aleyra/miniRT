/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:27:16 by lburnet           #+#    #+#             */
/*   Updated: 2021/04/05 11:17:42 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_cam(t_cam *cam)
{
	printf("c\t");
	printf("%f,%f,%f\t", cam->ptofview->x, cam->ptofview->y, cam->ptofview->z);
	printf("%f,%f,%f\t", cam->dir->x, cam->dir->y, cam->dir->z);
	printf("%d\n", cam->fov);
}

static void	print_light(t_light *light)
{
	printf("l\t");
	printf("%f,%f,%f", light->lightpt->x, light->lightpt->y, light->lightpt->z);
	printf("\t%f\t%d\n", light->br, light->rgb->i);
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
	t_cam	*cam;
	t_light	*light;
	t_obj	*obj;

	printf("R\t%d\t%d\n", mrt->res->x, mrt->res->y);
	printf("A\t%f\t%d\n\n", mrt->amb->ratio, mrt->amb->rgb->i);
	cam = mrt->cam;
	while (cam)
	{
		print_cam(cam);
		cam = cam->next;
	}
	light = mrt->light;
	while (light)
	{
		print_light(light);
		light = light->next;
	}
	printf("\n");
	obj = mrt->obj;
	while (obj)
	{
		print_obj1(obj);
		obj = obj->next;
	}
}
