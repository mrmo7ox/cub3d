/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:58:13 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/25 10:11:37 by moel-oua         ###   ########.fr       */
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

#define TITLE "cub3d"
#define	TSIZE 32
#define WIDTH 800 
#define MSCALE 0.25
#define PI 3.14159265359
#define HEIGHT 800

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct  s_gc
{
	void			*addres;
	struct  s_gc	*next;
}					t_gc;

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
	char	player;
}			t_map;

typedef	struct	s_player
{
	double		x;
	double		y;
	double	radius;
	int		turn_direction;
	int		walk_direction;
	double	rotation_angle;
	double	moving_speed;
	int		rotation_speed;
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
}			t_main;


// map
bool	file(char **dc, t_main *main);
bool	txtrs_clrs(t_main *main);
bool	chckadd_clrs(char **splited, t_main *main);
int		parse_color(char *color, t_main *main);
bool    parsemap(int last, t_main *main);
void	draw_map(t_main *main);
void	draw_player(t_main *main);
void	draw_cer(t_data *img ,size_t s_x , size_t s_y, size_t r, int color);

//player
bool	init_player(t_main *main);

// exec
void	run(t_main *main);
void	draw(t_main *main);
void	draw_pxl(t_data *img, int x, int y, int clr);
void	draw_sq(t_data *img ,size_t start_x , size_t start_y, size_t size, int color);
void	hooks_handler(t_main *main);
int		player_move(int keycode, t_main *main);

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