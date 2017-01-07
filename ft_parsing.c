/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:02:24 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/06 17:03:36 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_error_flags(char character)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(character);
	ft_putchar('\n');
	ft_putendl("usage: ls [-altrR] [file ...]");
}

static void			check_flags(t_opt *opt, char *str)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == 'r')
			opt->reverse = 1;
		else if (str[i] == 'R')
			opt->upper_r = 1;
		else if (str[i] == 'l')
			opt->listing = 1;
		else if (str[i] == 't')
			opt->date_sort = 1;
		else if (str[i] == 'a')
			opt->file_hide = 1;
		else
		{
			ft_error_flags(str[i]);
			exit(0);
		}
		opt->number_opt++;
	}
}

void				ft_parsing_ls(int ac, char **av, t_opt *opt)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "--") == 0)
		{
			opt->i_param = ++i;
			return ;
		}
		else if (av[i][0] == '-')
			check_flags(opt, av[i]);
		else if (av[i][0] != '-')
		{
			opt->i_param = i;
			return ;
		}
	}
}

void				creat_param(t_list **li, int ac, char **av)
{
	t_data			*data;
	int				i;
	struct stat		infos;

	i = 0;
	if ((*li) == NULL)
	{
		if (ac == 1 || (ft_strcmp(av[1], "--") == 0 && ac == 2))
		{
			ft_init_data(&data, ".", 0, 2);
			push_data(li, data);
			free(data->value);
			free(data);
			return ;
		}
		((ft_strcmp(av[1], "--")) == 0) ? ++i : 0;
		while (++i < ac)
		{
			stat(av[i], &infos);
			ft_init_data(&data, av[i], infos.st_mtime, (ft_strlen(av[i]) + 1));
			push_data(li, data);
			free(data->value);
			free(data);
		}
	}
}

void				creat_param_via_i_param(int ac, char **av, t_opt opt,
		t_list **li)
{
	t_data			*data;
	struct stat		infos;

	while (opt.i_param < ac)
	{
		(opt.listing) ? lstat(av[opt.i_param], &infos) :
			stat(av[opt.i_param], &infos);
		ft_init_data(&data, av[opt.i_param], infos.st_mtime,
				(ft_strlen(av[opt.i_param]) + 1));
		push_data(li, data);
		free(data->value);
		free(data);
		++opt.i_param;
	}
}
