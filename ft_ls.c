/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:59:59 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/05 14:20:09 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_count_character(t_dlist_check *li)
{
	t_dlistcell		*temporary;
	int				size;

	size = 0;
	if (li == NULL)
		return (0);
	temporary = li->begin;
	while (temporary)
	{
		if (temporary->valid == 0)
		{
			if (temporary->size_value > size)
				size = temporary->size_value;
		}
		temporary = temporary->next;
	}
	return (size);
}

int				display_error(t_dlist_check *li)
{
	t_dlistcell		*temporary;

	temporary = li->begin;
	while (temporary)
	{
		if (temporary->valid == -1)
		{
			ft_putstr("ft_ls: ");
			perror(temporary->value);
		}
		temporary = temporary->next;
	}
	return (1);
}

void			print_n(int space, int size_value)
{
	space -= size_value;
	while (space--)
		ft_putchar(' ');
}

int				display_files(t_dlist_check *li, int number_file, t_opt *opt)
{
	int				space;
	t_dlistcell		*temporary;
	static int		i;

	space = ft_count_character(li);
	i = 0;
	(opt->date_sort == 1) ? ft_tri_bulle_dlist_sort_time(&li) : 0;
	temporary = (opt->reverse) ? li->end : li->begin;
	while (temporary)
	{
		if (temporary->valid == 0)
		{
			(opt->listing) ? 0 : ft_putstr(temporary->value);
			if (--number_file > 0)
				print_n(space, ft_strlen(temporary->value));
		}
		temporary = (opt->reverse == 1) ? temporary->prev : temporary->next;
	}
	ft_putchar('\n');
	return (1);
}

t_number		ft_count_arg(t_dlist_check *li)
{
	struct stat		infos;
	t_dlistcell		*temporary;
	t_number		number;

	number = ft_initialization_number();
	temporary = li->begin;
	while (temporary)
	{
		if (lstat(temporary->value, &infos) == 0 && (S_ISREG(infos.st_mode)
				|| S_ISCHR(infos.st_mode) ||
				S_ISLNK(infos.st_mode) || S_ISBLK(infos.st_mode)))
			++number.files;
		else if (S_ISDIR(infos.st_mode))
		{
			temporary->valid = 1;
			++number.dir;
		}
		else
		{
			temporary->valid = -1;
			++number.error;
		}
		temporary = temporary->next;
	}
	return (number);
}

void			ft_start_ls(t_dlist_check *li, t_opt *opt)
{
	t_number		number;
	t_dlistcell		*temporary;
	int				i;

	number = ft_initialization_number();
	temporary = li->begin;
	number = ft_count_arg(li);
	i = (number.error > 0) ? display_error(li) : 0;
	i = (number.files > 0) ? display_files(li, number.files, opt) : 0;
	(i && number.dir > 0) ? ft_putchar('\n') : 0;
	while (temporary)
	{
		printf("%d --> %s\n", temporary->valid, temporary->value);
		temporary = temporary->next;
	}
}

int				main(int argc, char *argv[])
{
	t_opt				opt;
	t_dlist_check		*li;
	t_data				*data;

	li = new_dlist();
	if (argc == 1 || (argc >= 2 && ft_strcmp(argv[1], "--") == 0)
					|| (argc >= 2 && argv[1][0] != '-'))
		creat_param(&li, argc, argv);
	else
	{
		opt = ft_parsing_ls(argc, argv);
		if (!opt.i_param)
		{
			ft_init_data(&data, ".", 0, 2);
			li = push_data(li, data, 1);
			free(data);
		}
		else
			creat_param_via_i_param(argc, argv, opt, &li);
	}
	ft_tri_bulle_dlist_sort_ascii(&li);
	ft_start_ls(li, &opt);
	ft_clear_dlists(&li);
	return (0);
}
