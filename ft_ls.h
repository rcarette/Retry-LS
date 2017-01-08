/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:48:28 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/08 18:10:55 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>

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
	int						opt_one;
	int						number_opt;
}							t_opt;

typedef struct				s_number
{
	int						error;
	int						files;
	int						dir;
}							t_number;

typedef struct				s_dir
{
	t_list					*join_new_list;
	t_list					*read_list;
	char					*path;
}							t_dir;

typedef struct				s_infos
{
	int						size_name;
	int						size_group;
	int						size_octets;
	int						size_nlink;
}							t_infos;

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
void						ft_display_files(t_list **list, t_opt
					opt, t_number number);
void						ft_print_n(int space, int size);
void						ft_count_arg(t_list *list, t_number *number);
void						ft_display_error(t_list *list);
int							ft_count_character(t_list *list);
void						ft_listdup(t_list **list, t_list	**new_list);
void						ft_start_read_directory(t_list **list, t_opt opt,
					t_number number);
DIR							*ft_opendir(char *name);
void						ft_display(char *name);
int							ft_lenght_list(t_list *list);
void						ft_init_dir(t_dir *dir);
void						ft_error_open_dir(char *name);
void						ft_free_data(t_data **data);
void						ft_read_file(t_list *name, int size_term);
void						ft_display_one(t_list *list);
void						ft_display_listing(t_list *list);
void						ft_count_line_total(char *name, t_opt opt,
					int totals);
char						*ft_insert_slash(char *name, char *current);
void						ft_init_infos(t_infos *inf);
int							ft_getlen_int(int x);
t_infos						ft_get_infos(t_list *list);
void						ft_listing(t_list *list);
void						ft_get_symbolique(char *name, int i);
void						ft_print_link(int nlink, int size);
void						ft_print_group(int gid, int size);
void						ft_print_name(int uid, int size);
void						ft_print_octets(int octets, int size);
void						ft_print_dated(char *dated, time_t date);
#endif

