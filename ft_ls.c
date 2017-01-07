/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:59:59 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/07 09:53:15 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

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
	(number.dir >= 1) ? ft_listdup(list, &new_list) : 0;
	temporary = *list;
	(number.dir >= 1) ? ft_start_read_directory(list, opt, number) : 0;

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
	return (0);
}
