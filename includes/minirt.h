/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:08:46 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/19 15:41:33 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "fcntl.h"
# include "stdio.h"
# include "mlx.h"

//https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
/* Struct for miniRT ******************************************************** */

typedef struct s_rgb				t_rgb;
typedef void						(*t_pixel_setter)(void *, int, int, t_rgb);

struct s_rgb {
	int		i;
	int		t;
	int		b;
	int		g;
	int		r;
	float	fb;
	float	fg;
	float	fr;
};

typedef enum e_objtype {
	TYPE_UNKNOWN,
	TYPE_SPHERE,
	TYPE_PLANE,
	TYPE_TRIANGLE,
	TYPE_SQUARE,
	TYPE_CYLINDER
}	t_objtype;

typedef struct s_quad
{
	float	a;
	float	b;
	float	c;
	float	d;
	float	e;
	float	f;
	float	g;
	float	h;
	float	i;
	float	j;
}	t_quad;

typedef struct s_obj
{
	struct s_obj	*next;
	t_vec3			*center;
	union {
		double	diam;
		double	len;
	};
	t_rgb			*rgb;
	union {
		t_vec3	*norm;
		t_vec3	*dir;
	};
	double			height;
	t_vec3			*a;
	t_vec3			*b;
	t_vec3			*c;
	t_vec3			*d;
	t_quad			*quad;
	t_objtype		type;
}	t_obj;

typedef struct s_res
{
	unsigned int	x;
	unsigned int	y;
}					t_res;

typedef struct s_ambient
{
	double	ratio;
	t_rgb	*rgb;
}			t_ambient;

typedef struct s_cam
{
	t_vec3			*ptofview;
	t_vec3			*dir;
	float			fovr;
	struct s_cam	*next;
}					t_cam;

typedef struct s_light
{
	t_vec3				*lightpt;
	double				br;
	t_rgb				*rgb;
	struct s_light		*next;
}				t_light;

typedef struct s_mrt
{
	t_res		*res;
	t_ambient	*amb;
	t_cam		*cam;
	t_light		*light;
	t_obj		*obj;
	int			nb_cam;
}				t_mrt;

//what's endian ?
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pix;
	int		line_len;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*win;
	void	*mlx;
	t_mrt	*mrt;
	t_cam	*cam;
	t_data	*img;
	int		num_cam;
}			t_vars;

typedef struct s_coll
{
	float	t;
	union {
		t_vec3	n;
		t_vec3	c;
	};
}			t_coll;

typedef struct s_ray_tracer
{
	t_vec3	tmp;
	t_coll	tf_cac;
	t_obj	*o;
	t_obj	*fo;
	t_light	*li;
	t_coll	lray;
}			t_ray_tracer;

struct s_bmpfileheader {
	char	signature[2];
	int		file_size;
	int		reserved;
	int		data_offset;
} __attribute__((__packed__));

typedef struct s_bmpfileheader		t_bmpfileheader;

struct s_bmpinfoheader{
	int		size;
	int		width;
	int		height;
	short	planes;
	short	bitsperpix;
	int		compress;
	int		img_size;
	int		res_h;
	int		res_v;
	int		nb_color_used;
	int		nb_imp_color;
} __attribute__((__packed__));

typedef struct s_bmpinfoheader		t_bmpinfoheader;

struct s_bmpheader {
	t_bmpfileheader	bfh;
	t_bmpinfoheader	bih;
} __attribute__((__packed__));

typedef struct s_bmpheader			t_bmpheader;

typedef struct s_bmp{
	t_bmpheader	h;
	char		*body;
}	t_bmp;

/* Objects ****************************************************************** */
int		in_halfspace_sup(float t, t_vec3 *c, t_vec3 *r, t_obj *o);
int		in_halfspace_inf(float t, t_vec3 *c, t_vec3 *r, t_obj *o);
t_vec3	normal_to_cy(t_vec3 *n, t_vec3 pt, t_vec3 *o);
float	inter_lray(t_coll *lightray, t_vec3 *lightpt, t_obj *obj);
t_coll	intercept_lray_sp(t_vec3 *lightray, t_vec3 *lightpt, t_obj *sp);
t_coll	intercept_lray_pl(t_vec3 *lightray, t_vec3 *lightpt, t_obj *pl);
t_coll	intercept_lray_tr(t_vec3 *lightray, t_vec3 *lightpt, t_obj *tr);
t_coll	intercept_lray_sq(t_vec3 *lightray, t_vec3 *lightpt, t_obj *sq);
t_coll	intercept_lray_cy(t_vec3 *lightray, t_vec3 *lightpt, t_obj *cy);
int		ray_trace(t_vec3 *ray, t_mrt *mrt, t_vec3 *ptofview, t_rgb *color);
t_vec3	inter_quad_line_coeff(t_quad *quad, t_vec3 *c, t_vec3 *r);
float	discriminant(t_vec3 abc);
float	inter_quad_line_sol(t_vec3 abc, float d);
int		nb_sol(float delta);
t_coll	shooting_obj(t_obj *obj, t_vec3 *ray, t_vec3 *ptofview);
t_coll	shooting_cylinder(t_obj *cy, t_vec3 *ray, t_vec3 *ptofview);
t_coll	shooting_plane(t_obj *sp, t_vec3 *ray, t_vec3 *ptofview);
t_coll	shooting_triangle(t_obj *tr, t_vec3 *ray, t_vec3 *ptofview);
t_coll	shooting_square(t_obj *sq, t_vec3 *ray, t_vec3 *ptofview);
t_coll	shooting_sphere(t_obj *sp, t_vec3 *ray, t_vec3 *ptofview);
t_vec3	define_ray(unsigned int ik[2], t_mrt *mrt, float r, t_cam *cam);
int		ray_shooter(void *i, t_mrt *mrt, t_cam *cam, t_pixel_setter put_pixel);
int		in_square(t_obj *sq, t_vec3 p);
int		in_triangle(t_obj *tr, t_vec3 p);

/* Tool_box ***************************************************************** */
int		ft_atorgb(t_rgb *rgb, char *str);
int		ft_atovec3norm(t_vec3 *v, char *str);
int		ft_atovec3(t_vec3 *v, char *str);
t_vec3	vec3_rotate_axis(t_vec3 v, t_vec3 axis, float rad);
float	find_angle(t_vec3 a, t_vec3 b, int type);

/* Parsing ****************************************************************** */
typedef enum e_type_token
{
	KEYWORD,
	OPERATOR,
	STRING,
	CONSTANT,
	SPECIAL_CHAR,
	IDENTIFIER
}	t_type_token;

typedef struct s_token
{
	int		type;
	int		offset;
	char	*val;
}	t_token;

typedef enum e_state
{
	FIND_DATA,
	FIND_TOKEN,
	PARSE_KEYWORD,
	PARSE_OPERATOR,
	PARSE_STRING,
	PARSE_CONSTANT,
	PARSE_SPECIAL_CHAR,
	PARSE_IDENTIFIER,
	PARSE_ERROR,
	END_DATA
}	t_state;

int		ft_change_state(t_state stm, char *str, int *i, int gnl);
t_token	ft_tokenizer(t_state stm, char *str, int *i_id_nbt);
int		check_nb_param(int *i_id_nbt);
int		ft_parsing(t_mrt *mrt, int fd);

/* display ****************************************************************** */
//BLANK_n are for making correspondance between t_error and e_type_ID
typedef enum e_error {
	NO_ERROR,
	ERROR_FILE_NOT_RT,
	ERROR_IS_NOT_GOOD_SAVE,
	ERROR_NO_PARAM,
	ERROR_TOO_MANY_PARAM,
	ERROR_GNL,
	BLANK_6,
	BLANK_7,
	ERROR_PARSING_CHAR_BIS,
	BLANK_9,
	ERROR_IDENTIFIER,
	ERROR_PARSING_CHAR,
	ERROR_PARSING_PARAM,
	ERROR_RGB,
	ERROR_RES,
	ERROR_AMBIENT_RATIO,
	ERROR_VEC,
	ERROR_VECTOR_N,
	ERROR_FOV,
	ERROR_BRIGHTNESS_RATIO,
	ERROR_D_SP,
	ERROR_S_SQ,
	ERROR_D_OR_H_CY,
	ERROR_PTS_ALIGNED_TR,
	ERROR_NB_PARAM_R,
	ERROR_NB_PARAM_A,
	ERROR_NB_PARAM_C,
	ERROR_NB_PARAM_L,
	ERROR_NB_PARAM_SP,
	ERROR_NB_PARAM_PL,
	ERROR_NB_PARAM_SQ,
	ERROR_NB_PARAM_CY,
	ERROR_NB_PARAM_TR,
	ERROR_MALLOC,
	ERROR_NO_CAM,
	ERROR_BMP,
}	t_error;

typedef enum e_key{
	NO_KEY = 0,
	ESC = 53,
	LEFT_ARROW = 123,
	RIGHT_ARROW	= 124,
	DOWN_ARROW = 125,
	UP_ARROW = 126,
}	t_key;

void	header_bmp(t_bmp *bmp, t_mrt *mrt);
void	pixel_data_bmp(t_bmp *bmp, int x, int y, t_rgb color);
int		write_bmp(t_bmp bmp, int fd);
int		create_trgb(int t, int r, int g, int b);
int		init_color_initial(t_rgb *rgb, char *str);
void	float_color_to_char_int(t_rgb *rgb);
t_rgb	color_obj_and_amb(t_rgb *objc, t_ambient *amb);
t_rgb	c_add(t_rgb color1, t_rgb color2);
t_rgb	calc_c(t_light *li, t_obj *obj, t_vec3 ray, t_vec3 lray);
int		ft_display_error(int cas, t_mrt *mrt);
int		win_close(t_vars *v);
void	refresh(t_vars *v);
int		interact_key(int keycode, t_vars *vars);
void	print_mrt(t_mrt *mrt);
void	print_corner_sq(t_obj *o);
void	print_vec3(t_vec3 *v);
void	print_rgb(t_rgb *rgb);
void	print_cam(t_cam *c);
void	my_mlx_pixel_put(t_data *data, int x, int y, t_rgb color);

/* Struct managing ********************************************************** */
//BLANK_n are for making correspondance between t_error and e_type_ID
enum e_type_id
{
	NO_IDENTIFIER,
	ID_RESOLUTION,
	ID_AMBIENT_LIGHTINING,
	ID_CAMERA,
	ID_LIGHT,
	ID_SPHERE,
	ID_PLANE,
	ID_SQUARE,
	ID_CYLINDER,
	ID_TRIANGLE,
	ID_ERROR,
	BLANK_11,
	ID_TOO_MANY_PARAM,
	ID_BAD_RGB,
	ID_BAD_RES,
	ID_BAD_A_RAT,
	ID_BAD_PT,
	ID_BAD_NORM,
	ID_BAD_FOV,
	ID_BAD_B_RAT,
	ID_BAD_DIAM_S,
	ID_BAD_LEN_SQ,
	ID_BAD_D_OR_H_C,
	ID_BAD_PTS_T,
};

void	add_back_cam(t_mrt **mrt);
void	add_back_light(t_mrt **mrt);
void	add_back_obj(t_mrt **mrt);
void	add_spot(t_rgb *rgb, t_light *light);
void	complete_sq(t_obj *sq);
void	complete_tr(t_obj *tr);
void	delall_cam(t_cam **cam);
void	delall_light(t_light **light);
void	delall_obj(t_obj **obj);
void	free_mrt(t_mrt	*mrt);
void	init_quad_sp(t_obj *sp);
void	init_quad_pl(t_obj *pl);
void	init_quad_cy(t_obj *cy);
void	init_quad_tr(t_obj *tr);
void	init_struct_obj(t_obj **obj);
void	init_struct_light(t_light **li);
void	init_struct_cam(t_cam **cam);
void	init_struct_mrt(t_mrt **mrt);
void	init_struct_rgb(t_rgb *rgb);
t_cam	*lstlast_cam(t_cam *cam);
t_light	*lstlast_light(t_light *light);
t_obj	*lstlast_obj(t_obj *lst);
void	set_struct(t_mrt *mrt, t_token token, int *i_id_nbt);
void	set_struct_id(t_mrt *mrt, t_token token, int *i_id_nbt);
void	set_struct_id_obj(t_mrt *mrt, t_token token, int *i_id_nbt);
void	set_struct_const(t_mrt *mrt, t_token token, int *i_id_nbt);
void	assign_double_and_check_error(
			double *d, char *str, int *err, int nb_err);
void	set_struct_ambiant(t_mrt *mrt, t_token token, int *i_id_nbt);
void	set_struct_cam(t_mrt *mrt, t_token token, int *i_id_nbt);
void	set_struct_light(t_mrt *mrt, t_token token, int *i_id_nbt);
void	set_struct_sphere(t_mrt *mrt, t_token token, int *i_id_nbt);
void	set_struct_plane(t_mrt *mrt, t_token token, int *i_id_nbt);
void	set_struct_square(t_mrt *mrt, t_token token, int *i_id_nbt);
void	set_struct_cylinder(t_mrt *mrt, t_token token, int *i_id_nbt);
void	set_struct_triangle(t_mrt *mrt, t_token token, int *i_id_nbt);
void	set_struct_res(t_mrt *mrt, t_token token, int *i_id_nbt);

#endif
