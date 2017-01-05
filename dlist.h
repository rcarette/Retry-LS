/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:13:26 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/03 09:03:40 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct				s_dlistcell
{
	char					*value;
	int						size_value;
	time_t					date_value;
	struct s_dlistcell		*next;
	struct s_dlistcell		*prev;
}							t_dlistcell;

typedef struct				s_dlist_check
{
	int						size_cell;
	struct s_dlistcell		*begin;
	struct s_dlistcell		*end;
}							t_dlist_check;

typedef struct				s_data
{
	char					*value;
	time_t					date_value;
	int						size_value;
}							t_data;

int							is_empty_dlist(t_dlist_check *li);
t_dlist_check				*new_dlist(void);
t_dlistcell					*creat_new_cell(char *data, int size_value,
							time_t date_value);
t_dlist_check				*push_data(t_dlist_check *li, t_data data,
							int choice);
void						print_d_list(t_dlist_check *li, int choice);
t_dlist_check				*ft_clear_dlists(t_dlist_check **li);
void						ft_clear_dcell(t_dlist_check **li);
void						ft_tri_bulle_dlist_sort_time(t_dlist_check **li);
void						ft_tri_bulle_dlist_sort_ascii(t_dlist_check **li);

#endif
