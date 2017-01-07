# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/29 01:54:40 by rcarette          #+#    #+#              #
#    Updated: 2017/01/06 17:47:24 by rcarette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRCS = ft_tri_bulle_dlist.c\
	   push_data.c\
	   creat_new_cell.c\
	   ft_ls.c\
	   ft_initialization.c\
	   ft_parsing.c\
	   ft_clear_list.c\
	   ft_list_reverse.c\

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft/ re
	gcc -g -c $(SRCS)
	gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	/bin/rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all
