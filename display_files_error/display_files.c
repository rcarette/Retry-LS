/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 07:34:08 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/07 08:11:16 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_display_files(t_list **list, t_opt opt, t_number number)
{
	int			space;
	t_list		*temporary;
	int			files;

	files = number.files;
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
			if (--files > 0 && opt.listing == 0)
				ft_print_n(space, ft_strlen(temporary->value));
		}
		temporary = temporary->next;
	}
	(opt.listing == 0) ? ft_putchar('\n') : 0;
}


