# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 17:04:02 by moel-oua          #+#    #+#              #
#    Updated: 2025/09/14 14:01:42 by moel-oua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror 
MFLAGS  =  -lmlx -lX11 -lXext -lm

NAME    = cub3D
HEADERS = cub.h

GNLSRC  = gnl/get_next_line_utils.c gnl/get_next_line.c
USRC    = utils/ft_countchr.c utils/ft_rmlstsp.c utils/splitcolor.c \
          utils/miniatoi.c utils/ft_putstr_fd.c utils/ft_strlen.c \
          utils/ft_gc.c utils/ft_substr.c utils/ft_memcpy.c \
          utils/ft_strcmp.c utils/ft_whitespaces.c utils/ft_split.c
PSRC    = parsing/file_utils.c parsing/map_checker.c parsing/txtrs_clrs_utils.c parsing/map_utils.c parsing/file.c parsing/txtrs_clrs.c \
          parsing/map.c parsing/colors.c
ESEC    = exec/textures_utils.c exec/hundle_textures.c exec/render_utils.c exec/casting3.c exec/player_utils2.c exec/player_utils.c exec/casting2.c  exec/render.c exec/casting.c exec/player.c exec/utils.c exec/draw_utils.c exec/img_utils.c exec/hooks.c exec/run.c

SRCS    = main.c $(PSRC) $(USRC) $(GNLSRC) $(ESEC)
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
