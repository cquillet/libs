# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/10 19:47:16 by cquillet          #+#    #+#              #
#    Updated: 2018/03/01 16:59:33 by cquillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRLIBFT = libft
NAMELIBFT = libft.a

DIRLIBFTPRINTF = ft_printf
NAMELIBFTPRINTF = libftprintf.a

VERSION_GET = "$(shell sw_vers | grep "ProductVersion:" | grep -o "[0-9]\+\.[0-9]\+")"
SIERRA = "10.12"
EL_CAPITAN = "10.11"
#ifeq ($(VERSION_GET), $(EL_CAPITAN))
DIRMLX = x11_minilibx
#endif
ifeq ($(VERSION_GET), $(SIERRA))
DIRMLX = minilibx_macos_sierra
else
DIRMLX = minilibx_macos
endif
NAMELIBMLX = libmlx.a
HEADERMLX = mlx.h

DIRHEADER = includes

RM = rm -f

.PHONY: all clean fclean re header

all: $(NAMELIBFT) $(NAMELIBFTPRINTF) $(NAMELIBMLX)

$(NAMELIBFT): header
	make -C $(DIRLIBFT)

$(NAMELIBFTPRINTF): $(NAMELIBFT)
	make -C $(DIRLIBFTPRINTF)

$(NAMELIBMLX): header
	make -C $(DIRMLX)
	ln -fs $(DIRMLX)/$(NAMELIBMLX) $(NAMELIBMLX)

header:
	ln -fs ../$(DIRMLX)/$(HEADERMLX) $(DIRHEADER)/$(HEADERMLX)

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
