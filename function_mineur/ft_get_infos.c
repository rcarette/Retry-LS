/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:24:14 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/08 16:26:09 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_infos		ft_get_infos(t_list *list)
{
	t_infos			inf;
	struct stat		infos;
	struct passwd	*name;
	struct group	*group;

	ft_init_infos(&inf);
	while (list)
	{
		lstat(list->value, &infos);
		if (infos.st_nlink > inf.size_nlink)
			inf.size_nlink = infos.st_nlink;
		if (infos.st_size > inf.size_octets)
			inf.size_octets = infos.st_size;
		name = getpwuid(infos.st_uid);
		if (ft_strlen(name->pw_name) > inf.size_name)
			inf.size_name = ft_strlen(name->pw_name);
		group = getgrgid(infos.st_gid);
		if (ft_strlen(group->gr_name) > inf.size_group)
			inf.size_group = ft_strlen(group->gr_name);
		list = list->next;
	}
	inf.size_octets = ft_getlen_int(inf.size_octets);
	inf.size_nlink = ft_getlen_int(inf.size_nlink);
	return (inf);
}
