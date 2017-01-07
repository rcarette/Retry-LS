/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:59:59 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/07 07:27:54 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

void			ft_count_arg(t_list *list, t_number *number)
{
	struct stat		infos;

	while (list)
	{
		if (lstat(list->value, &infos) == 0)
		{
			if (S_ISREG(infos.st_mode) || S_ISCHR(infos.st_mode)
				|| S_ISBLK(infos.st_mode) || S_ISLNK(infos.st_mode)
				|| S_ISSOCK(infos.st_mode) || S_ISFIFO(infos.st_mode))
				++number->files;
			else if (S_ISDIR(infos.st_mode))
			{
				list->valid = 1;
				++number->dir;
			}
		}
		else
		{
			list->valid = -1;
			++number->error;
		}
		list = list->next;
	}
}

void			ft_display_error(t_list *list)
{
	while (list)
	{
		if (list->valid == -1)
		{
			ft_putstr("ft_ls: ");
			perror(list->value);
		}
		list = list->next;
	}
}

int				ft_count_character(t_list *list)
{
	int		size;

	size = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		if (list->valid == 0)
			if (ft_strlen(list->value) > size)
				size = list->size_value;
		list = list->next;
	}
	return (size);
}

void			ft_print_n(int space, int size)
{
	space -= size;
	while (space--)
		ft_putchar(' ');
}

void			ft_display_files(t_list **list, t_opt opt, t_number number)
{
	int			space;
	t_list		*temporary;

	space = ft_count_character(*list);
	if (opt.date_sort)
		ft_tri_bulle_dlist_sort_time(list);
	(opt.reverse) ? ft_list_reverse(list) : 0;
	temporary = *list;
	while (temporary)
	{
		if (temporary->valid == 0)
		{
			(opt.listing == 0) ? ft_putstr(temporary->value) : 0;
			if (--number.files > 0 && opt.listing == 0)
				ft_print_n(space, ft_strlen(temporary->value));
		}
		temporary = temporary->next;
	}
	(opt.listing == 0) ? ft_putchar('\n') : 0;
}

void		ft_listdup(t_list **list, t_list	**new_list)
{
	t_list			*temporary;
	struct stat		infos;
	t_data			*data;

	temporary = *list;
	while (temporary)
	{
		if (temporary->valid == 1)
		{
			stat(temporary->value, &infos);
			ft_init_data(&data, temporary->value, infos.st_mtime,
				(ft_strlen(temporary->value) + 1));
			push_data(new_list, data);
			free(data->value);
			free(data);
		}
		temporary = temporary->next;
	}
	ft_clear_list(list);
	*list = *new_list;
}

void			ft_start_ls(t_list **list, t_opt opt)
{
	t_number	number;
	t_list		*new_list;
	t_list		*temporary;
	
	new_list = NULL;
	number = ft_initialization_number();
	ft_count_arg(*list, &number);
	(number.error > 0) ? ft_display_error(*list) : 0;
	(number.files > 0) ? ft_display_files(list, opt, number) : 0;
	if (number.dir > 0 && (number.error > 0 || number.files > 0))
		ft_putchar('\n');
	(number.dir) ? ft_listdup(list, &new_list) : 0;
	temporary = *list;

}

int				main(int argc, char *argv[])
{
	t_opt				opt;
	t_list				*li;
	t_data				*data;

	li = new_list();
	opt = ft_initialization_opt();
	if (argc == 1 || (argc >= 2 && ft_strcmp(argv[1], "--") == 0)
					|| (argc >= 2 && argv[1][0] != '-'))
		creat_param(&li, argc, argv);
	else
	{
		ft_parsing_ls(argc, argv, &opt);
		if (!opt.i_param)
		{
			ft_init_data(&data, ".", 0, 2);
			push_data(&li, data);
			free(data);
		}
		else
			creat_param_via_i_param(argc, argv, opt, &li);
	}
	ft_tri_bulle_dlist_sort_ascii(&li);
	ft_start_ls(&li, opt);
	ft_clear_list(&li);
	return (0);
}
