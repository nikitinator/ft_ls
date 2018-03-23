/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:05:50 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/23 13:14:30 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>

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

typedef struct	s_dir
{
	char		*name;
	struct stat d_stat;
	DIR			*dir_p;
}				t_dir;

typedef struct	s_file
{
	char		*name;
	struct stat f_stat; //stat_p is not pointer (mind the name)
}				t_file;

typedef struct	s_dirs
{
	t_dir		*arr;
	t_ushort	size;//int§	
}				t_dirs;

typedef struct	s_files
{
	t_file		*arr;
	t_ushort	size;	
}				t_files;

void		print_usage(void);

int			get_arg_keys(int argc, char **argv, t_params *par);
int			get_arg_files(int argc, char **argv, t_dirs *dirs, t_files *files);

void		list_files(t_files files, t_params params);
void		list_dirs(t_dirs dirs, t_params params);

void		list_dir(t_dir dir, t_params params);

void		free_dirs(t_dirs dirs);
void		free_files(t_files files);

void		reverse_files(t_files files);
void		print_list(t_files);
void		print_list_long(t_files);


void		sort_files(t_files files, char time_modif);
//void		sort_files_time_modif(t_files files);
//void		sort_files_lexicograph(t_files files);

void		file_list_to_arr(t_list *file_list, t_files *files);
void		dir_list_to_arr(t_list *dir_list, t_dirs *dirs);

void		print_list_long(t_files files);


void		del_list(void *content, size_t content_size);
void		get_files_from_dir(t_dir dir, t_files *files, t_params params); //limit params to one parameter
void		get_files_dirs_from_dir(t_dir dir, t_files *files, t_dirs *dirs,
			t_params params); //limit params to one parameter

void		swap_files(t_file *file_1, t_file *file_2);
void		swap_dirs(t_dir *dir_1, t_dir *dir_2);
void		reverse_files(t_files files);
void		reverse_dirs(t_dirs dirs);

#endif
