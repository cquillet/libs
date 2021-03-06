# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 17:39:08 by cquillet          #+#    #+#              #
#    Updated: 2018/04/26 17:55:51 by cquillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libft.a

CC = gcc

DIROBJ = .

DIRLIBS = ..

DIRHEADER = $(DIRLIBS)/includes
CFLAGS = $(DIRHEADER:%=-I%) -Wall -Wextra -Werror

SRC = ./calc/float_2f.c ./calc/int_2d.c ./calc/scale.c ./calc/tab_bin.c \
./calc/int_3d.c ./math/matrix_func.c ./math/matrix_ops.c \
./math/quat_ops.c ./math/quat_vector.c ./math/quaternion.c \
./math/vector.c ./math/vector_ops.c \
./math/complex.c ./math/complex_ops.c ./math/cplx_elem.c math/polynomial.c \
./math/poly_math.c ./math/poly_ops.c ./math/poly_print.c ./math/poly_real.c \
./math/poly_test.c ./math/ft_abs.c ./math/ft_power.c \
./conv/ft_atoi.c \
./conv/ft_atoi_base.c ./conv/ft_itoa.c ./conv/ft_itoa_base.c \
./gnl/get_next_line.c ./graph/box.c ./graph/boxf.c ./graph/boxf_cplx.c \
./graph/box_redim.c ./graph/boxf_redim.c \
./graph/draw_line.c ./graph/landsea.c graph/draw_box.c \
./graph/mlx_image.c ./graph/pixel.c ./graph/rgb.c ./graph/rgbf.c \
./graph/wavelength.c \
./graph/window.c ./is/barely_equals.c ./is/ft_isalnum.c ./is/ft_isalpha.c \
./is/ft_isascii.c ./is/ft_isdigit.c ./is/ft_ishex.c ./is/ft_isnumber.c \
./is/ft_isprint.c ./lst/ft_lstadd.c ./lst/ft_lstdel.c ./lst/ft_lstdelone.c \
./lst/ft_lstiter.c ./lst/ft_lstlen.c ./lst/ft_lstmap.c ./lst/ft_lstnew.c \
./mem/ft_bzero.c ./mem/ft_memalloc.c ./mem/ft_memccpy.c ./mem/ft_memchr.c \
./mem/ft_memcmp.c ./mem/ft_memcpy.c ./mem/ft_memdel.c ./mem/ft_memdel2dim.c \
./mem/ft_memlen.c ./mem/ft_memmove.c ./mem/ft_memset.c ./put/ft_putcenter.c \
./put/ft_putchar.c ./put/ft_putchar_fd.c ./put/ft_putendl.c \
./put/ft_putendl_fd.c ./put/ft_putnbr.c ./put/ft_putnbr_base.c \
./put/ft_putnbr_base_fd.c ./put/ft_putnbr_fd.c ./put/ft_putstr.c \
./put/ft_putstr_fd.c ./str/ft_lenchar.c ./str/ft_replace.c ./str/ft_strcat.c \
./str/ft_strcenter.c ./str/ft_strchr.c ./str/ft_strclr.c ./str/ft_strcmp.c \
./str/ft_strcpy.c ./str/ft_strdel.c ./str/ft_strdup.c ./str/ft_strequ.c \
./str/ft_striter.c ./str/ft_striteri.c ./str/ft_strjoin.c ./str/ft_strlcat.c \
./str/ft_strlen.c ./str/ft_strmap.c ./str/ft_strmapi.c ./str/ft_strmset.c \
./str/ft_strncat.c ./str/ft_strncmp.c ./str/ft_strncpy.c ./str/ft_strnequ.c \
./str/ft_strnew.c ./str/ft_strnstr.c ./str/ft_strpad.c ./str/ft_strrchr.c \
./str/ft_strset.c ./str/ft_strsplit.c ./str/ft_strstr.c ./str/ft_strsub.c \
./str/ft_strtrim.c ./str/ft_tolower.c ./str/ft_toupper.c

OBJ = $(SRC:%.c=%.o)

RM = rm -f

.PHONY: all clean fclean

all: header $(NAME)

header:
	make -C $(DIRLIBS) header

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
