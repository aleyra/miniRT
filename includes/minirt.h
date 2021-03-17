/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:08:46 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/17 15:20:50 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "maths3d.h"
# include "stdio.h"
# include "errors.h"
# include "mlx.h"
//https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
typedef union u_rgb {
	int	i;
	struct {
		unsigned char	t;
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
	};
}	t_rgb;

typedef enum e_objtype {
	TYPE_UNKNOWN,
	TYPE_SPHERE,
	TYPE_PLANE,
	TYPE_TRIANGLE,
	TYPE_SQUARE,
	TYPE_CYLINDER
}	t_objtype;

typedef struct s_obj
{
	struct s_obj	*next;
	t_vec3			center;
	union {
		float	diam;
		float	len;
	};
	t_rgb			rgb;
	union {
		t_vec3	norm;
		t_vec3	dir;
	};
	float			height;
	t_vec3			a;
	t_vec3			b;
	t_vec3			c;
	t_vec3			d;
	t_objtype		type;
}	t_obj;

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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pix;
	int		line_len;
	int		endian;
}			t_data;

int	in_triangle(t_obj tr, t_vec3 p);
int	in_square(t_obj sq, t_vec3 p);
#endif
