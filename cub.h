/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:58:13 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/28 14:21:48 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# define TITLE "cub3D"
# define WIDTH 1920
# define HEIGHT 1080
# define FOV 60
# define TSIZE 64
# define NBR_RAYS WIDTH

enum
{
	W = 119,
	S = 115,
	A = 97,
	D = 100,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361,
	ON_DESTROY = 17,
	ON_EXIT = 65307
};

typedef enum s_angle
{
	E_LEFT,
	E_RIGHT,
	E_UP,
	E_DOWN,
	E_NULL,
}					t_angle;
typedef struct s_corners
{
	int				top_left_x;
	int				top_left_y;
	int				top_right_x;
	int				top_right_y;
	int				bottom_left_x;
	int				bottom_left_y;
	int				bottom_right_x;
	int				bottom_right_y;
}					t_corners;

typedef struct s_gc
{
	void			*addres;
	struct s_gc		*next;
}					t_gc;

typedef struct s_draw_data
{
	int				line_height;
	int				draw_debut;
	int				draw_fin;
	int				color;
}					t_draw_data;

typedef struct s_dist
{
	double			dist;
	struct s_dist	*next;
}					t_dist;

typedef struct s_textures
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	bool			done;
}					t_txtrs;
typedef struct s_txtr_cnt
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_txtr_cnt;

typedef struct s_clrs
{
	int				f;
	int				c;
	bool			done;
}					t_clrs;

typedef struct s_map
{
	char			**content;
	int				tsize;
	char			player;
}					t_map;

typedef struct s_player
{
	float			x;
	float			y;
	float			width;
	float			size;
	float			height;
	float			angle_de_rotation;
	float			walk_speed;
	float			turn_speed;
}					t_plr;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	struct s_main	*main;
}					t_vars;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_keys
{
	bool			w;
	bool			s;
	bool			d;
	bool			a;
	bool			l;
	bool			r;
	bool			exit;
}					t_keys;

typedef struct s_raycast
{
	double			player_x;
	double			player_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			cote_dist_x;
	double			cote_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_mur_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
}					t_raycast;

typedef struct s_ray
{
	float			ray_angle;
	float			wallhitx;
	float			wallhity;
	float			distance;
	bool			is_vert;
	bool			en_haut;
	bool			en_bas;
	bool			a_gauche;
	bool			a_droit;
	int				hit_content;
}					t_rays;

typedef struct s_main
{
	char			**fcnt;
	t_gc			**gc;
	t_clrs			*colors;
	t_txtrs			*txtrs;
	t_map			*map;
	t_data			*img;
	t_plr			*p;
	t_vars			*vars;
	t_keys			*keys;
	t_dist			**dist;
	t_rays			**rays;
	t_txtr_cnt		**txts_cnt;
}					t_main;

typedef struct s_minimap_data
{
	t_main			*main;
	int				x;
	int				y;
	int				ix;
	int				iy;
}					t_minimap_data;

typedef struct s_line_params
{
	double			start_x;
	double			start_y;
	double			len;
	double			angle;
	int				color;
}					t_line_params;

typedef struct s_line_vars
{
	double			incx;
	double			incy;
	double			step;
	double			i;
	double			current_x;
	double			current_y;
}					t_line_vars;

// load textures
bool				load_textures(t_main *main);
void				clean_textures(t_main *main);
unsigned int		get_pixel_color(t_txtr_cnt *texture, int x, int y);
t_txtr_cnt			*get_mur_texture(t_main *main, int i);
void				draw_textured_mur(t_main *main, t_txtr_cnt *texture, int i,
						t_draw_data *data);
double				calculate_mur_x(t_rays *ray, t_main *main);
int					clamp_tex_x(int tex_x, int texture_width);

// map
bool				file(char **dc, t_main *main);
bool				txtrs_clrs(t_main *main);
bool				chckadd_clrs(char **splited, t_main *main);
int					parse_color(char *color, t_main *main);
bool				parsemap(int last, t_main *main);
void				draw_line(t_main *main, t_line_params *params);
// render
void				render(t_main *main);
void				raycast_initial(t_main *main,
						float ray_angle, t_raycast *rc);
void				draw_plafond(t_main *main, int i, int draw_debut);
void				draw_sol(t_main *main, int i, int draw_fin);

// player
bool				init_player(t_main *main);
int					player_move(t_main *main);
double				normalize_angle(double angle);
void				set_if_not_wall(t_main *main, double new_x, double new_y);
bool				player_pos(t_main *main);
void				set_player_angle(t_main *main);

// ray casting
bool				init_rays(t_main *main);
void				set_ray_direction(t_main *main, float ray_angle,
						int ray_id);
void				cast_ray(t_main *main, float ray_angle, int ray_id);
void				cast(t_main *main);

// exec
void				run(t_main *main);
void				draw(t_main *main);
void				draw_pxl(t_data *img, int x, int y, int clr);
void				hooks_handler(t_main *main);

// mxl hooks and img
int					close_win(t_main *main);
bool				initkeys(t_main *main);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);

// gc
t_gc				*ft_newgc(void *addres);
bool				ft_addgc(t_gc **head, t_gc *node);
void				*ft_malloc(t_main *main, size_t size);
void				ft_cleangc(t_gc **head);

// gnl
char				*ft_strjoin(const char *s1, const char *s2, t_main *main);
char				*ft_strchr(const char *s, int c);
char				*gnl(int fd, t_main *main);
char				*ft_strdup(const char *source, t_main *main);

// utils
int					ft_countchr(char chr, char *str);
size_t				ft_strlen(const char *str);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_substr(char *s, unsigned int start, size_t len,
						t_main *main);
int					ft_strcmp(const char *s1, const char *s2);
bool				ft_whitespaces(char chr);
void				ft_putstr_fd(char *str, int fd);
bool				is_allwspace(char *str);
char				**ft_splitwhite(char *str, t_main *main, int i, int j);
size_t				ft_dplen(char **dp);
int					miniatoi(const char *ptr);
char				**ft_split(char *str, t_main *main, int i, int j);
char				*ft_rmlstsp(char *str, t_main *main);
bool				check_up(char **map, int x, int y);
bool				check_down(char **map, int x, int y);
bool				check_left(char **map, int x, int y);
bool				check_right(char **map, int x, int y);
char				*ft_rmlstspmap(char *str, t_main *main);
char				*formating(char *path, t_main *main);
// textures and colors and map and file utils
bool				txturs_test(char *path, char **txtvar);
bool				chckadd_txtrs(char **splited, char *original, t_main *main);
bool				clrs_txtrs_done(t_main *main);
int					end_map(t_main *main);
bool				map_checker(char **map, int x, int y);
bool				valid_path(char *path, t_main *main);
size_t				bfr_size(int fd, t_main *main);
bool				addcnt(int fd, t_main *main);
bool				valid_ext(char *path, t_main *main, char *ext_cmp);

#endif