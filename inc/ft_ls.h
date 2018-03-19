/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:05:50 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/19 14:24:35 by snikitin         ###   ########.fr       */
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
	struct stat stat_p;
}				t_files;


typedef struct	s_dirs
{
	char		*name[];
	DIR			*dir_p[];
	t_ushort	size;	
}				t_dirs;

typedef struct	s_files
{
	char		*name[];
	struct stat stat_p[];
	t_ushort	size;	
}				t_files;

void		print_usage(void);
int			get_arg_keys(int argc, char **argv, t_params *par);
int			get_arg_files(int argc, char **argv, t_dirs *dirs, t_files *files);

void		list_files(t_files files, t_params params);
void		list_dirs(t_dirs dirs, t_params params);

#endif
