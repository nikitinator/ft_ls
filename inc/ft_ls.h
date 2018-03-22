/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:05:50 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/22 13:37:20 by snikitin         ###   ########.fr       */
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
	DIR			*dir_p;
}				t_dir;

typedef struct	s_file
{
	char		*name;
	struct stat stat_p; //stat_p is not pointer (mind the name)
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

void		del_list(void *content, size_t content_size);

#endif
