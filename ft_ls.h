/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:48:28 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/06 17:47:04 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include "sys/types.h"
# include "sys/stat.h"
# include "errno.h"
# include "dirent.h"

typedef struct				s_list
{
	char					*value;
	int						size_value;
	time_t					date_value;
	int						valid;
	struct s_list			*next;
}							t_list;

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

t_list						*creat_new_cell(char *data, int size_value,
							time_t date_value, int valid);
void						push_data(t_list **li, t_data *data);
void						ft_tri_bulle_dlist_sort_time(t_list **li);
void						ft_tri_bulle_dlist_sort_ascii(t_list **li);


t_opt						ft_initialization_opt(void);
void						ft_init_data(t_data **data, char *value,
					time_t date_value, int size_value);
void						ft_parsing_ls(int ac, char **av, t_opt *opt);
void						creat_param_via_i_param(int ac, char **av,
					t_opt opt,t_list **li);
void						creat_param(t_list **li, int ac, char **av);
t_number					ft_initialization_number(void);
void						ft_count_arg(t_list *list, t_number *number);
void						print_n(int space, int size_value);
void						ft_clear_list(t_list **list);
t_list						*new_list(void);
void						ft_list_reverse(t_list **begin_list);
#endif

