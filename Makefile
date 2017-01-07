# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/29 01:54:40 by rcarette          #+#    #+#              #
#    Updated: 2017/01/07 09:19:42 by rcarette         ###   ########.fr        #
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
	   display_files_error/display_files.c\
	   display_files_error/display_error.c\
	   display_files_error/ft_list_dup.c\
	   function_mineur/ft_print_n.c\
	   function_mineur/ft_count_character.c\
	   function_mineur/ft_count_arg.c\
	   function_mineur/ft_lenght_list.c\
	   read_directory/ft_start_read_directory.c\
	   read_directory/error/ft_opendir.c\
	   read_directory/error/ft_error_open_dir.c\

OBJ = ft_tri_bulle_dlist.o\
	   push_data.o\
	   creat_new_cell.o\
	   ft_ls.o\
	   ft_initialization.o\
	   ft_parsing.o\
	   ft_clear_list.o\
	   ft_list_reverse.o\
	   display_files.o\
	   display_error.o\
	   ft_list_dup.o\
	   ft_print_n.o\
	   ft_count_character.o\
	   ft_count_arg.o\
	   ft_start_read_directory.o\
	   ft_opendir.o\
	   ft_error_open_dir.o\
	   ft_lenght_list.o\


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
