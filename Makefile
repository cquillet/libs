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

DIRLIBFT = libft
NAMELIBFT = libft.a

DIRLIBFTPRINTF = ft_printf
NAMELIBFTPRINTF = libftprintf.a

VERSION_GET = $(shell sw_vers | grep "ProductVersion:" | grep -o "[0-9]\+\.[0-9]\+")
SIERRA = "10.12"
EL_CAPITAN = "10.11"
DIRMLX = x11_minilibx
ifeq ($(VERSION_GET), $(SIERRA))
DIRMLX = minilibx_macos_sierra
#endif
#ifeq ($(VERSION_GET), $(EL_CAPITAN))
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
	@echo $(NAMELIBFT)
	make -C $(DIRLIBFT)

$(NAMELIBFTPRINTF): $(NAMELIBFT)
	@echo $(NAMELIBFTPRINTF)
	make -C $(DIRLIBFTPRINTF)

$(NAMELIBMLX): header
	@echo $(NAMELIBMLX)
	make -C $(DIRMLX)
	$(RM) $(NAMELIBMLX)
	ln -s $(DIRMLX)/$(NAMELIBMLX) $(NAMELIBMLX)

header:
	@echo header
	$(RM) $(DIRHEADER)/$(HEADERMLX)
	ln -s ../$(DIRMLX)/$(HEADERMLX) $(DIRHEADER)/$(HEADERMLX)

clean:
	make -C $(DIRLIBFT) clean
	make -C $(DIRLIBFTPRINTF) clean
	make -C $(DIRMLX) clean

fclean:
	make -C $(DIRLIBFT) fclean
	make -C $(DIRLIBFTPRINTF) fclean
	make -C $(DIRMLX) clean
	$(RM) $(NAMELIBMLX)
	$(RM) $(DIRHEADER)/$(HEADERMLX)

re: fclean all
