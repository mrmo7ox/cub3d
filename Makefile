# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 17:04:02 by moel-oua          #+#    #+#              #
#    Updated: 2025/07/30 09:31:49 by moel-oua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = #-Wall -Wextra -Werror -g3 -fsanitize=address
MFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
GNLSRC = gnl/get_next_line_utils.c gnl/get_next_line.c
USRC =  utils.c/ft_rmlstsp.c utils.c/ft_countchr.c utils.c/splitcolor.c utils.c/miniatoi.c utils.c/ft_putstr_fd.c ./utils.c/ft_strlen.c utils.c/ft_gc.c utils.c/ft_substr.c ./utils.c/ft_memcpy.c utils.c/ft_strcmp.c utils.c/ft_whitespaces.c utils.c/ft_split.c
PSRC = parsing/map_utils.c parsing/file.c parsing/txtrs_clrs.c parsing/map.c parsing/colors.c
ESEC = exec/ray_casting.c exec/alpha.c exec/utils.c exec/player.c exec/minimap.c exec/draw_urtils.c exec/img_utils.c exec/hooks.c exec/run.c 
SRCS = main.c $(PSRC) $(USRC) $(GNLSRC) $(ESEC)
OBJECTS = $(SRCS:.c=.o)
HEADERS = cub.h
NAME = cub

all: $(NAME)
	make clean

$(NAME):$(OBJECTS)
	$(CC) $(CFLAGS) $(MFLAGS) $(OBJECTS) -o $@

 %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	clean 