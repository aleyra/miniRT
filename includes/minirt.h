/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:08:46 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/08 10:25:34 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "maths3d.h"
# include "stdio.h"

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

typedef struct s_obj
{
	char			type[3];
	t_vec3			o;
	float			d;
	t_rgb			rgb;
	t_vec3			n;
	float			h;
	t_vec3			a;
	t_vec3			b;
	t_vec3			c;
	t_vec3			d;
	struct s_obj	*next;
}				t_obj;

typedef struct s_res
{
	unsigned int	x;
	unsigned int	y;
}					t_res;

typedef struct s_ambient
{
	float	ratio;
	t_rgb	rgb;
}			t_ambient;

typedef struct s_cam
{
	t_vec3			o;
	t_vec3			d;
	unsigned int	fov;
	struct s_cam	*next;
}					t_cam;

typedef struct s_light
{
	t_vec3				o;
	float				br;
	t_rgb				rgb;
	struct s_light		*next;
}				t_light;

typedef struct s_mrt
{
	t_res		r;
	t_ambient	a;
	t_cam		cam;
	t_light		light;
	t_obj		obj;
}				t_mrt;

int	ft_display_error(int cas);
#endif
