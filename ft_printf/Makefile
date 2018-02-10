# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/10 15:58:59 by cquillet          #+#    #+#              #
#    Updated: 2018/02/10 17:47:02 by cquillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libftprintf.a

DIRSRC = src
DIROBJ = obj

CC = gcc

DIRLIBFT = ../libft
DIRHEADER = . $(DIRLIBFT)/includes
CFLAGS = $(DIRHEADER:%=-I%) -Wall -Wextra -Werror

DIRLIB = ..
LDFLAGS = $(DIRLIB:%=-L%)
LIBS = libft.a
LDLIBS = $(LIBNAME:lib%.a=-l%)

SRC = c_char.c c_double.c c_int.c c_intmax.c c_long.c c_longdouble.c \
c_longlong.c c_pointers.c c_short.c c_size_t.c c_str.c c_wchar.c characters.c \
floats.c format.c int_display.c integers.c pointers.c printf.c read.c \
strings.c type.c type_nb.c

OBJ = $(SRC:%.c=$(DIROBJ)/%.o)

RM = rm -f

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(DIRLIBFT)
	ar rc $(NAME) $^
	ranlib $(NAME)

$(DIROBJ)/%.o: $(DIRSRC)/%.c
	$(shell mkdir -p $(DIROBJ))
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	make -C $(DIRLIBFT) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(DIRLIBFT) fclean
	$(RM) $(NAME)
	$(RM) -r $(DIROBJ)

re: fclean all
