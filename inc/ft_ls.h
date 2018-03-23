/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:05:50 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/23 21:06:49 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>

# define MONTH 4
# define DAY 8
# define TIME 11 
# define YEAR 20 

typedef unsigned char t_byte;
typedef unsigned short t_ushort;
typedef unsigned int	t_uint;

typedef struct	s_space_num
{
	t_byte		owner;
	t_byte		group;
	t_byte		size;
	t_byte		links;
}				t_space_num;

typedef struct	s_params
{
	char	long_format;
	char	recursive;
	char	reverse;
	char	show_hidden;
	char	time_modif;

	char	show_curr_dir;
}				t_params;

typedef struct	s_file
{
	char		*name;
	struct stat f_stat; //stat_p is not pointer (mind the name)
}				t_file;

typedef struct	s_files
{
	t_file		*arr;
	t_ushort	size;	
}				t_files;

typedef			s_add_file_info
{
	t_space_num	n_space;
	char		*full_path;
	char		*owners;
	char		*gropups;
}				t_add_file_info;

void		print_usage(void);

int			get_arg_keys(int argc, char **argv, t_params *par);
int			get_arg_files(int argc, char **argv, t_files *dirs, t_files *files);

void		list_files(t_files files, char *dir_path, t_params params);
void		list_dirs(t_files dirs, t_params params);
void		list_dir(t_file dir, t_params params);

void		free_dirs(t_files dirs);//
void		free_files(t_files files);

void		reverse_files(t_files files);
void		print_list(t_files);

void		sort_files(t_files files, char time_modif);

void		file_list_to_arr(t_list *file_list, t_files *files);

void		print_list_long(t_files files, char *dir_path);


void		del_list(void *content, size_t content_size);
void		get_files_from_dir(t_file dir, t_files *files, t_byte show_hidden);
void		get_files_dirs_from_dir(t_file dir, t_files *files, t_files *dirs,
			t_byte show_hidden);

void		swap_files(t_file *file_1, t_file *file_2);
void		reverse_files(t_files files);

void		get_space_num(t_files files, char **ownders, char **groups, t_space_num *n_space);

int			is_dir(mode_t st_mode);
int			is_sym_link(mode_t st_mode);
int			is_hidden(char *name);

char		*get_full_path(char *dir_name, char *file_name);

void		print_n_spaces(int n);
void		print_total(t_files files);
void		print_file_type(mode_t st_mode);
void		print_file_modes(mode_t st_mode);
void		print_sticky_bit(char *dir_path , char *file_name);

void		print_mod_time(time_t mod_time);

#endif
