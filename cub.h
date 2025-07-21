/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:58:13 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/21 19:47:51 by moel-oua         ###   ########.fr       */
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

#define DEBUG true

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
	char	player;
}			t_map;

typedef struct  s_main
{
	char	**fcnt;
	t_gc	**gc;
	t_clrs	*colors;
	t_txtrs	*txtrs;
	t_map	*map;
}			t_main;


// map
bool	file(char **dc, t_main *main);
bool	txtrs_clrs(t_main *main);
bool	chckadd_clrs(char **splited, t_main *main);
int		parse_color(char *color, t_main *main);
bool    parsemap(int last, t_main *main);



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

#endif