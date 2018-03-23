/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:34:07 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/22 18:48:57 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"



static int		open_arg_to_lists(char **argv,
		t_list **file_list, t_list **dir_list)
{
	DIR			*dir_p;
	struct stat	file_st;

	*file_list = NULL;
	*dir_list = NULL;
	while (*argv)
	{
		if (!lstat(*argv, &file_st))
		{
			if ((dir_p = opendir(*argv)))
				ft_list_push_front
					(dir_list, &(t_dir){ft_strdup(*argv), file_st, dir_p}, sizeof(t_dir));
			else
				ft_list_push_front
					(file_list, &(t_file){ft_strdup(*argv), file_st}, sizeof(t_file));
		}
		else
		{
			ft_putendl(*argv);
			ft_putendl("NEMA FILE, dlava ukraini");//TODO razberis s errorami	
		}
		argv++;
	}	
	return (0);
}

int		get_arg_files(int argc, char **argv, t_dirs *dirs, t_files *files)
{
	int		i;

	t_list *file_list;
	t_list *dir_list;
	
	ft_bzero(dirs, sizeof(t_dirs));
	ft_bzero(files, sizeof(t_files));
	i = 1;
	while(i < argc && *(argv[i]) == '-')
		i++;
	if (i == argc)
		argv[--i] = "."; 
	open_arg_to_lists(argv + i, &file_list, &dir_list);
	file_list_to_arr(file_list, files);
	
		dir_list_to_arr(dir_list, dirs);
	ft_lstdel(&file_list, del_list);
	ft_lstdel(&dir_list, del_list);
	return (0);
}
