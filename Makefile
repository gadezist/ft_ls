# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abytko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 20:02:17 by abytko            #+#    #+#              #
#    Updated: 2018/03/26 16:52:42 by abytko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRCDIR = ./src/
OBJDIR = ./obj/
INC = ./includes/
LIBDIR = ./lib/
SRC = ft_ls.c ft_lstnew_entry.c ft_lst_pushback.c ft_lst_sort.c\
	ft_print_list.c ft_lst_rev.c ft_lst_sort_time.c \
	ft_lst_maxlen.c ft_maxlen.c ft_intlen.c ft_total_blk.c \
	ft_get_file_or_dir.c ft_show_tab.c ft_get_index_lst.c \
	ft_lst_free.c ft_print_file_err.c
FLAG = -Wall -Werror -Wextra
LIBFTFLAGS = -lft -L $(LIBDIR)/libft/
LIBFTPRINTFFLAGS = -lftprintf -L $(LIBDIR)/ft_printf/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME):$(OBJ)
	make -C $(LIBDIR)/libft/
	make -C $(LIBDIR)/ft_printf/
	gcc $(FLAG) -o $(NAME) $(OBJ) -I $(INC) $(LIBFTFLAGS) $(LIBFTPRINTFFLAGS)

$(OBJDIR)%.o: %.c
	gcc -c $< -o $@ $(FLAG) -I $(INC)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBDIR)/libft
	make clean -C $(LIBDIR)/ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)/libft
	make fclean -C $(LIBDIR)/ft_printf

re: fclean all

vpath %.c $(SRCDIR)
