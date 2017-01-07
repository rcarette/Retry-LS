/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_read_directory.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 07:59:35 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/07 17:00:24 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static char				*ft_insert_slash(char *name, char *current)
{
	char	*temporary;
	char	*str;

	if (name[ft_strlen(name) - 1] == '/')
		str = ft_strjoin(name, current);
	else
	{
		str = ft_strjoin(name, ft_strcmp(name, "/") ? "/" : NULL);
		temporary = str;
		str = ft_strjoin(temporary, current);
		free(temporary);
	}
	return (str);
}

static void				join_dir(t_list **list, t_list **join_new_list,
						t_opt opt)
{
	t_list		*t;
	t_list		*d;

	(opt.date_sort == 0) ? ft_tri_bulle_dlist_sort_ascii(join_new_list) : 0;
	(opt.date_sort == 1) ? ft_tri_bulle_dlist_sort_time(join_new_list) : 0;
	(opt.reverse) ? ft_list_reverse(join_new_list) : 0;
	if (ft_lenght_list(*list) == 1)
	{
		(*list)->next = (*join_new_list);
		return ;
	}
	t = (*list);
	d = (*join_new_list);
	while (d->next)
		d = d->next;
	d->next = (*list)->next;
	(*list)->next = (*join_new_list);
}

void					ft_read_directory(t_list **new_list, t_opt opt)
{
	char				*str;
	struct winsize		w;
	
	ioctl(0, TIOCGWINSZ, &w);
	(opt.date_sort == 0) ? ft_tri_bulle_dlist_sort_ascii(new_list) : 0;
	(opt.date_sort == 1) ? ft_tri_bulle_dlist_sort_time(new_list) : 0;
	(opt.reverse) ? ft_list_reverse(new_list) : 0;
	if (!opt.listing)
		ft_read_file(*new_list, w.ws_col);
	ft_clear_list(new_list);
	ft_putchar('\n');
}

void					ft_treatement_dir(char *name, t_opt opt, t_list **list,
						DIR *rep)
{
	struct dirent	*current;
	t_data			*data;
	struct stat		info;
	t_dir			dir;

	ft_init_dir(&dir);
	while ((current = readdir(rep)))
	{
		dir.path = ft_insert_slash(name, current->d_name);
		lstat(dir.path, &info);
		ft_init_data(&data, dir.path, info.st_mtime, (ft_strlen(dir.path) + 1));
		if (opt.upper_r == 1)
			if (ft_strcmp(".", current->d_name) != 0 &&
					ft_strcmp("..", current->d_name) != 0)
				if (opt.file_hide == 1 || current->d_name[0] != '.')
					if (S_ISDIR(info.st_mode))
						push_data(&dir.join_new_list, data);
		if (opt.file_hide == 1 || current->d_name[0] != '.')
		{
			push_data(&dir.read_list, data);
			ft_free_data(&data);
		}
	}
	(dir.join_new_list != NULL) ? join_dir(list, &dir.join_new_list, opt) : 0;
	(dir.read_list != NULL) ? ft_read_directory(&dir.read_list, opt) : 0;
}

void					ft_start_read_directory(t_list **list, t_opt opt,
		t_number n)
{
	t_list		*temporary;
	DIR			*rep;

	while (*list)
	{
		if (n.files >= 1 || n.error >= 1 || n.dir > 1 || opt.upper_r == 1)
			ft_display((*list)->value);
		if (!(rep = ft_opendir((*list)->value)))
		{
			temporary = (*list);
			ft_error_open_dir((*list)->value);
			(*list) = (*list)->next;
		}
		else
		{
			temporary = (*list);
			ft_treatement_dir((*list)->value, opt, list, rep);
			(*list) = (*list)->next;
		}
		((*list)) ? ft_putchar('\n') : 0;
		(rep != NULL) ? closedir(rep) : 0;
		free(temporary->value);
		free(temporary);
	}
}
