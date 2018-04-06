/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:34:07 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/06 17:55:38 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		open_arg_to_lists_long(char **argv, t_list **file_list,
		t_list **dir_list, t_list **error_list)
{
	struct stat	f_stat;

	*file_list = NULL;
	*dir_list = NULL;
	*error_list = NULL;
	while (*argv)
	{
		if (!lstat(*argv, &f_stat))
			if (is_dir(f_stat.st_mode))
				ft_list_push_front(dir_list,
						&(t_file){ft_strdup(*argv), f_stat}, sizeof(t_file));
			else
				ft_list_push_front(file_list,
						&(t_file){ft_strdup(*argv), f_stat}, sizeof(t_file));
		else
			ft_list_push_front(error_list,
						&(t_file){ft_strdup(*argv), f_stat}, sizeof(t_file));
		argv++;
	}
	return (0);
}

static int		open_arg_to_lists(char **argv, t_list **file_list,
		t_list **dir_list, t_list **error_list)
{
	struct stat	f_stat;

	*file_list = NULL;
	*dir_list = NULL;
	while (*argv)
	{
		if ((!stat(*argv, &f_stat)) || (!lstat(*argv, &f_stat)))
			if (is_dir(f_stat.st_mode))
				ft_list_push_front(dir_list,
						&(t_file){ft_strdup(*argv), f_stat}, sizeof(t_file));
			else
				ft_list_push_front(file_list,
						&(t_file){ft_strdup(*argv), f_stat}, sizeof(t_file));
		else
			ft_list_push_front(error_list,
						&(t_file){ft_strdup(*argv), f_stat}, sizeof(t_file));
		argv++;
	}
	return (0);
}

int				get_arg_files(char **argv, t_params params, t_arg *argf)
{
	t_list	*file_list;
	t_list	*dir_list;
	t_list	*error_list;

	ft_bzero(argf, sizeof(t_arg));
	if (!*argv)
		*(--argv) = ".";
	if (params.long_format)
		open_arg_to_lists_long(argv, &file_list, &dir_list, &error_list);
	else
		open_arg_to_lists(argv, &file_list, &dir_list, &error_list);
	file_list_to_arr(file_list, &argf->files);
	file_list_to_arr(dir_list, &argf->dirs);
	file_list_to_arr(error_list, &argf->errors);
	ft_lstdel(&file_list, del_list);
	ft_lstdel(&dir_list, del_list);
	ft_lstdel(&error_list, del_list);
	return (0);
}
