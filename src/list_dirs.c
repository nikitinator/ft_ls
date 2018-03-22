/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:33:44 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/22 13:40:05 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_hidden(char *name)
{
	return (*name == '.');
}

static void	print_dir_name(char *name)
{
	ft_putstr(name);
	ft_putendl(":");
}

t_files	get_files_from_dir(t_dir dir, t_params params) //limit params to one parameter
{
	t_files 		files;
	t_list			*file_list;
	struct dirent	*dp;
	struct stat		file_stat;
	char			*full_file_name;
	
	ft_bzero(&files, sizeof(t_files));
	file_list = 0;
	while ((dp = readdir(dir.dir_p)))
	{
		full_file_name = ft_strjoin(dir.name, dp->d_name);
		ft_putstr("\t\t\t");
		ft_putendl(full_file_name);
		//ft_putendl("readdir");
		if (!stat(full_file_name, &file_stat))
		{
			//ft_putendl("get_files stat");
			//ft_putendl("");
			if (params.show_hidden == 1 || !is_hidden(dp->d_name))
			{
				ft_list_push_front(&file_list, //oooohhhhhhhhhhhh should i check it
					&(t_file){dp->d_name, file_stat}, sizeof(t_file));
				files.size++;
			}
		}
		free(full_file_name);
	}
	file_list_to_arr(file_list, &files);
	ft_lstdel(&file_list, del_list);
	return (files);
}

void	list_dirs(t_dirs dirs, t_params params)
{
	int		i;
	t_files	files;

	(void)params;
	if (dirs.size == 0)
		return ;
	i = 0;
	while (i < dirs.size)
	{
		if (dirs.size > 1)
			print_dir_name(dirs.arr[i].name);
		//ft_putendl("get_files entry");
		files = get_files_from_dir(dirs.arr[i], params); //do i need to send params there?
		//ft_putendl("get_files exit");
		list_files(files, params);
		free_files(files);
		i++;
	}
}
