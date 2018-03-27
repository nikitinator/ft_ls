/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:05:50 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/27 18:49:02 by snikitin         ###   ########.fr       */
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

# define MAX_FILENAME_LEN 256

typedef unsigned char t_byte;
typedef unsigned short t_ushort;
typedef unsigned int	t_uint;

typedef struct	s_space_num
{
	t_byte		owner;
	t_byte		group;
	t_byte		size;
	t_byte		links;
	t_byte		major;
	t_byte		minor;
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
	struct stat f_stat; 
}				t_file;

typedef struct	s_files
{
	t_file		*arr;
	t_ushort	size;	
}				t_files;

typedef struct	s_add_file_info
{
	char		*full_path;
	char		*owner;
	char		*group;
	t_space_num	n_space;
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
int			get_files_from_dir(t_file dir, t_files *files, t_byte show_hidden);
int			get_files_dirs_from_dir(t_file dir, t_files *files, t_files *dirs,
			t_byte show_hidden);

void		swap_files(t_file *file_1, t_file *file_2);
void		reverse_files(t_files files);

void		get_space_num(t_files files, t_add_file_info *f_i);
int			get_owners_groups(t_files files, t_add_file_info *inf);


int			is_blck_dev(mode_t st_mode);
int			is_char_dev(mode_t st_mode);
int			is_dir(mode_t st_mode);
int			is_sym_link(mode_t st_mode);
int			is_hidden(char *name);

char		*append_names_file_to_dir(char *dir_name, char *file_name);
int			get_full_paths(t_files files, char *dir_name, t_add_file_info *f_i);

void		handle_sym_links(t_files files, t_add_file_info *f_i);

void		print_one_line(t_file file, t_add_file_info i);

void		print_n_spaces(int n);
void		print_total(t_files files);
void		print_type(mode_t st_mode);
void		print_modes(mode_t st_mode);
void		print_sticky_bit(char *full_path);//ensure that STICKY is the right word

void		print_mod_time(time_t mod_time);

short		get_digit_num(int n);
void		ft_putnchar(int n , char c);

#endif
