/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 07:34:08 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/08 17:13:47 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		dupli_lists(t_list *list, t_list **new_list)
{
	t_data			*data;
	struct stat		infos;

	while (list)
	{
		if (list->valid == 0)
		{
			lstat(list->value, &infos);
			ft_init_data(&data, list->value, infos.st_mtime,
					(ft_strlen(list->value) + 1));
			push_data(new_list, data);
			free(data->value);
			free(data);
		}
		list = list->next;
	}
}

void	ft_listing(t_list *list)
{
	t_list		*new_list;
	t_list		*temporary;
	
	new_list = NULL;
	dupli_lists(list, &new_list);
	ft_display_listing(new_list);
	ft_clear_list(&new_list);
}

void	ft_display_files(t_list **list, t_opt opt, t_number number)
{
	int			space;
	t_list		*temporary;
	int			files;

	files = number.files;
	space = ft_count_character(*list);
	(opt.date_sort == 1) ? ft_tri_bulle_dlist_sort_time(list) : 0;
	(opt.reverse) ? ft_list_reverse(list) : 0;
	temporary = *list;
	while (temporary)
	{
		if (temporary->valid == 0)
		{
			if (opt.opt_one > 0 && opt.opt_one > opt.listing)
				ft_putendl(temporary->value);
			else
			{
				(opt.listing == 0) ? ft_putstr(temporary->value) : 0;
					if (--files > 0 && opt.listing == 0)
						ft_print_n(space, ft_strlen(temporary->value));
			}
		}
		temporary = temporary->next;
	}
	(opt.listing == 0) ? ft_putchar('\n') : 0;
}


