# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abytko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 20:02:17 by abytko            #+#    #+#              #
#    Updated: 2018/03/22 19:15:29 by abytko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBDIR = libft
#LIBOBJ = $(LIBDIR)/*.o
LIB = $(LIBDIR)/libft.a
SRCDIR = src
SRC = ft_printf.c ft_widechar.c ft_decimal_arg.c ft_flag.c ft_nondecimal_arg.c\
	ft_precision.c ft_string_and_char.c ft_width.c ft_stringwidechar.c\
	ft_type_flag.c ft_flagoctotorp.c ft_widthwide.c
IDIR = includes
INC = $(IDIR)/libftprintf.h
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean

%.o: $(SRCDIR)/%.c
	gcc -c $<

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)
	cp $(LIB) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJ) *~

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all
