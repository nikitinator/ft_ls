/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:05:50 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/09 12:21:03 by snikitin         ###   ########.fr       */
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

# define HALF_YEAR 15768000

# define MAX_FILENAME_LEN 256

# define MAJOR(x) ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define MINOR(x) ((int32_t)((x) & 0xffffff))

# define MINORBITS 20
# define MINORMASK ((1U << MINORBITS) - 1)

typedef unsigned char	t_byte;
typedef unsigned int	t_uint;

typedef struct			s_space_num
{
	t_byte		owner;
	t_byte		group;
	t_byte		size;
	t_byte		links;
	t_byte		major;
	t_byte		minor;
}						t_space_num;

typedef struct			s_params
{
	char	long_format;
	char	recursive;
	char	reverse;
	char	show_hidden;
	char	time_modif;
	t_byte	first_time;
}						t_params;

typedef struct			s_file
{
	char		*name;
	struct stat f_stat;
}						t_file;

typedef struct			s_files
{
	t_file		*arr;
	size_t		size;
}						t_files;

typedef struct			s_arg
{
	t_files		files;
	t_files		dirs;
	t_files		errors;
}						t_arg;

typedef struct			s_add_file_info
{
	char		*full_path;
	char		*owner;
	char		*group;
	t_space_num	n_space;
}						t_add_file_info;

void					print_usage(void);

int						get_arg_keys(char ***argv, t_params *par);
int						get_arg_files(char **argv, t_params par, t_arg *argf);

int						get_files_from_dir(t_file dir, t_byte show_hidden,
							t_files *files);
int						get_files_dirs_from_dir(t_file dir, t_byte show_hidden,
							t_files *files, t_files *dirs);
void					del_list(void *content, size_t content_size);
void					file_list_to_arr(t_list *file_list, t_files *files);

void					swap_files(t_file *file_1, t_file *file_2);
void					sort_files(t_files files, char time_modif);
void					free_files(t_files files);
void					reverse_files(t_files files);

void					get_space_num(t_files files, t_add_file_info *f_i);
int						get_owners_groups(t_files files, t_add_file_info *inf);

int						is_blck_dev(mode_t st_mode);
int						is_char_dev(mode_t st_mode);
int						is_dir(mode_t st_mode);
int						is_sym_link(mode_t st_mode);
int						is_hidden(char *name);

char					*append_names_file_to_dir(char *dir_name,
							char *file_name);
int						get_full_paths(t_files files, char *dir_name,
							t_add_file_info *f_i);
void					handle_sym_links(t_files files, t_add_file_info *f_i);

void					list_files(t_files files, char *dir_path,
							t_params params);
void					list_dirs(t_files dirs, t_params params);
int						list_dir(t_file dir, t_params params);

void					print_files(t_files files);
void					print_files_long(t_files files, char *dir_path);

void					print_dir_name(char *name, t_byte *first_time);
void					print_one_line(t_file file, t_add_file_info i);
void					print_n_spaces(int n);
void					print_total(t_files files);
void					print_type(mode_t st_mode);
void					print_modes(mode_t st_mode);
void					print_has_ext_attr(char *full_path);
void					print_major_minor(dev_t	st_rdev, t_byte major_spaces,
							t_byte minor_spaces);
void					print_mod_time(time_t mod_time);

void					putnbr_align(int n, t_byte num_space);
void					putstr_align(char *owner, t_byte num_space);

short					get_digit_num(int n);

void					puterror_perm_denied(char *file_name);
void					puterror_no_key(char key);
void					puterror_no_file(char *file_name);

char					*ft_itoa_base(t_uint value, int base);
#endif
