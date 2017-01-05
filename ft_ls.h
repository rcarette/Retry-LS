/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:48:28 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/05 12:36:26 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include "sys/types.h"
# include "sys/stat.h"
# include "errno.h"

typedef struct				s_dlistcell
{
	char					*value;
	int						size_value;
	time_t					date_value;
	int						valid;
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
	int						valid;
}							t_data;

typedef struct				s_opt
{
	int						reverse;
	int						date_sort;
	int						upper_r;
	int						listing;
	int						file_hide;
	int						i_param;
	int						number_opt;
}							t_opt;

typedef struct				s_number
{
	int						error;
	int						files;
	int						dir;
}							t_number;

int							is_empty_dlist(t_dlist_check *li);
t_dlist_check				*new_dlist(void);
t_dlistcell					*creat_new_cell(char *data, int size_value,
							time_t date_value, int valid);
t_dlist_check				*push_data(t_dlist_check *li, t_data *data,
							int choice);
void						print_d_list(t_dlist_check *li, int choice);
t_dlist_check				*ft_clear_dlists(t_dlist_check **li);
void						ft_clear_dcell(t_dlist_check **li);
void						ft_tri_bulle_dlist_sort_time(t_dlist_check **li);
void						ft_tri_bulle_dlist_sort_ascii(t_dlist_check **li);


t_opt						ft_initialization_opt(void);
void						ft_init_data(t_data **data, char *value,
					time_t date_value, int size_value);
t_opt						ft_parsing_ls(int ac, char **av);
void						creat_param_via_i_param(int ac, char **av,
					t_opt opt,t_dlist_check **li);
void						creat_param(t_dlist_check **li, int ac, char **av);
t_number					ft_initialization_number(void);
#endif

