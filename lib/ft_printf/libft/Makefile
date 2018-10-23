# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abytko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 13:07:40 by abytko            #+#    #+#              #
#    Updated: 2018/01/31 19:58:49 by abytko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = *.c
OBJECT = *.o
FLAG = -Wall -Werror -Wextra
H = ./

all: $(NAME)

$(NAME):
	gcc  $(FLAG) -c $(SRC) -I$(H)
	ar rc $(NAME) $(OBJECT)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
