/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:58:13 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/30 14:16:23 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <mlx.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#define TITLE "cub3d"
#define	MSIZE 400
#define MSCALE 0.25
#define WIDTH 500
#define PI 3.14159
#define HEIGHT 500
#define FOV 60

// enum {
// 	W = 13,
// 	S = 1,
// 	A = 0,
// 	D = 2,
// 	UP = 126,
// 	DOWN = 125,
// 	RIGHT = 123,
// 	LEFT = 124,
// 	ON_DESTROY = 17,
// 	ON_EXIT = 53
// };
enum {
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

typedef enum	s_angle
{
	E_LEFT,
	E_RIGHT,
	E_UP,
	E_DOWN,
	E_NULL,
}				t_angle;


typedef struct  s_gc
{
	void			*addres;
	struct  s_gc	*next;
}					t_gc;

typedef struct  s_dist
{
	double  		dist;
	struct  s_dist	*next;
}					t_dist;

typedef	struct	s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	bool	done;
}			t_txtrs;

typedef	struct	s_clrs
{
	int	f;
	int	c;
	bool done;
}			t_clrs;

typedef	struct	s_map
{
	char	**content;
	int		width;
	int		height;
	int		tsize;
	char	player;
}			t_map;

typedef	struct	s_player
{
	double		x;
	double		y;
	double		steps;
	double		size;
	double	radius;
	int		turn_direction;
	int		walk_direction;
	double	rotation_angle;
	double	moving_speed;
	double	rotation_speed;
}			t_plr;


typedef struct	s_vars {
	void			*mlx;
	void			*win;
	struct  s_main *main;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_keys {
	bool	w;
	bool	s;
	bool	d;
	bool	a;
	bool	l;
	bool	r;
	bool	exit;
}				t_keys;

typedef struct  s_main
{
	char	**fcnt;
	t_gc	**gc;
	t_clrs	*colors;
	t_txtrs	*txtrs;
	t_map	*map;
	t_data	*img;
	t_plr	*p;
	t_vars	*vars;
	t_keys	*keys;
	t_dist	**dist;
}			t_main;


// map
bool	file(char **dc, t_main *main);
bool	txtrs_clrs(t_main *main);
bool	chckadd_clrs(char **splited, t_main *main);
int		parse_color(char *color, t_main *main);
bool    parsemap(int last, t_main *main);
void	draw_map(t_main *main);
void	draw_player(t_main *main);
void	draw_line(t_main *main , double s_x, double s_y, double len, double angle ,int color);
double	torad(int angle);
bool	iswall(t_main *main, double x, double y);
void	draw_bg(t_main *main);
void	draw_bg_2(t_main *main);
void	cast_single_ray(t_main *main,double angle , double x, double y);
double	normalize_angle(double angle);
void	draw_minimap(t_main *main);
double	cast_ray(t_main *main, double angle);

//ray_list
t_dist	*ft_newdist(t_main *main, double dist);
bool	ft_adddist(t_dist **head, t_dist *node);
void ft_cleandist(t_dist **head);

//
bool check_wall_at_position(t_main *main, double x, double y);
bool check_collision_with_radius(t_main *main, double x, double y);
bool can_move_to(t_main *main, double new_x, double new_y);
void handle_wall_sliding(t_main *main, double target_x, double target_y, double *final_x, double *final_y);
bool move_player_with_collision(t_main *main, double target_x, double target_y);
void collosion(t_main *main);
void render_3d_view(t_main *main);
//player
bool	init_player(t_main *main);


//ray casting
t_angle	get_angle(double angle);
void	set_player_angle(t_main *main);


// exec
void	run(t_main *main);
void	draw(t_main *main);
void	draw_pxl(t_data *img, int x, int y, int clr);
void	draw_sq(t_data *img ,size_t start_x , size_t start_y, size_t size, int color);
void	hooks_handler(t_main *main);
int		player_move( t_main *main);

//mxl hooks and img
int		close_win(t_main *main);
int		key_hook(int keycode, t_main *main);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);



//gc 
t_gc	*ft_newgc(void *addres);
bool	ft_addgc(t_gc **head, t_gc *node);
void	*ft_malloc(t_main *main, size_t size);
void	ft_cleangc(t_gc **head);

//gnl
char	*ft_strjoin(const char *s1, const char *s2, t_main *main);
char	*ft_strchr(const char *s, int c);
char	*gnl(int fd, t_main *main);
char	*ft_strdup(const char *source, t_main *main);

// utils 
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len, t_main *main);
int		ft_strcmp(const char *s1, const char *s2);
bool	ft_whitespaces(char chr);
void	ft_putstr_fd(char *str, int fd);
bool	is_allwspace(char *str);
char	**ft_splitwhite(char *str, t_main *main, int i, int j);
size_t	ft_dplen(char **dp);
int		miniatoi(const char *ptr);
int		ft_isdigit(int c);
char	**ft_split(char *str, t_main *main, int i, int j);
int		ft_countchr(char chr, char *str);
char	*ft_rmlstsp(char *str, t_main *main);
bool	check_up(char **map, int x, int y);
bool	check_down(char **map, int x, int y);
bool	check_left(char **map, int x, int y);
bool	check_right(char **map, int x, int y);
char	*ft_rmlstspmap(char *str, t_main *main);

#endif