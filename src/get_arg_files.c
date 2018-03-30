/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:34:07 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/30 19:26:27 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		open_arg_to_lists(char **argv,
		t_list **file_list, t_list **dir_list)
{
	struct stat	f_stat;

	*file_list = NULL;
	*dir_list = NULL;
	while (*argv)
	{
		if (!lstat(*argv, &f_stat))
		{
			if (is_dir(f_stat.st_mode))
				ft_list_push_front(dir_list,
						&(t_file){ft_strdup(*argv), f_stat}, sizeof(t_file));
			else
				ft_list_push_front(file_list,
						&(t_file){ft_strdup(*argv), f_stat}, sizeof(t_file));
		}
		else
			puterror_no_file(*argv);
		argv++;
	}
	return (0);
}

int				get_arg_files(int argc, char **argv, t_files *dirs, t_files *files)
{
	int		i;
	t_list	*file_list;
	t_list	*dir_list;

	ft_bzero(dirs, sizeof(t_files));
	ft_bzero(files, sizeof(t_files));
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] 
			&& !ft_strequ(argv[i], "--"))
			i++;
	if (i < argc && ft_strequ(argv[i], "--"))
		i++;
	if (i == argc)
		argv[--i] = ".";
	open_arg_to_lists(argv + i, &file_list, &dir_list);
	file_list_to_arr(file_list, files);
	file_list_to_arr(dir_list, dirs);
	ft_lstdel(&file_list, del_list);
	ft_lstdel(&dir_list, del_list);
	return (0);
}
