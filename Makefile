# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/10 19:47:16 by cquillet          #+#    #+#              #
#    Updated: 2018/02/10 20:35:21 by cquillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VERSION_GET = $(shell sw_vers | grep "ProductVersion:" | grep -o "[0-9]\+\.[0-9]\+")
SIERRA = 10.12
EL_CAPITAN = 10.11

DIRLIBFT = libft
NAMELIBFT = libft.a

DIRLIBFTPRINTF = ft_printf
NAMELIBFTPRINTF = libftprintf.a

ifeq ($(VERSION_GET), $(SIERRA))
DIRMLX = minilibx_macos_sierra
else
DIRMLX = minilibx_macos
endif
NAMELIBMLX = libmlx.a

DIRLIBS = $(DIRLIBFT) $(DIRLIBFTPRINTF) $(DIRMLX)

RM = rm -f

.PHONY: all clean fclean re

all:
	make -C $(DIRLIBFT)
	make -C $(DIRLIBFTPRINTF)
	make -C $(DIRMLX)
	mv $(DIRMLX)/$(NAMELIBMLX) .

clean:
	make -C $(DIRLIBFT) clean
	make -C $(DIRLIBFTPRINTF) clean
	make -C $(DIRMLX) clean

fclean:
	make -C $(DIRLIBFT) fclean
	make -C $(DIRLIBFTPRINTF) fclean
	make -C $(DIRMLX) clean
	$(RM) $(NAMELIBMLX)

re: fclean all
