/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:10:52 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/27 18:45:56 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_files_from_dir(t_file dir, t_files *files, t_byte show_hidden)
{
	t_list			*file_list;
	char			*full_file_name;
	DIR				*dir_p;
	struct dirent	*dp;
	struct stat		file_stat;
	
	
	file_list = 0;
	if (!(dir_p = opendir(dir.name)))//permission denied
		return (1);
	while ((dp = readdir(dir_p)))
	{
		full_file_name = append_names_file_to_dir(dir.name, dp->d_name);
		if (!lstat(full_file_name, &file_stat))
		{
			if (show_hidden || !is_hidden(dp->d_name))
			{
				ft_list_push_front(&file_list, //oooohhhhhhhhhhhh should i check it
					&(t_file){ft_strdup(dp->d_name), file_stat}, sizeof(t_file));
			}
		}
		free(full_file_name);
	}
	file_list_to_arr(file_list, files);
	ft_lstdel(&file_list, del_list);
	closedir(dir_p);
	return (0);
}

int		get_files_dirs_from_dir(t_file dir, t_files *files, t_files *dirs,
		t_byte show_hidden)
{
	t_list			*file_list;
	t_list			*dir_list;
	char			*full_file_name;
	struct dirent	*dp;
	struct stat		file_stat;
	DIR				*dir_p;
	
	file_list = 0;
	dir_list = 0;
	if (!(dir_p = opendir(dir.name)))
		return (1);
	while ((dp = readdir(dir_p)))
	{
		full_file_name = append_names_file_to_dir(dir.name, dp->d_name);
		if (!lstat(full_file_name, &file_stat))
		{
			if (show_hidden == 1 || !is_hidden(dp->d_name))
			{
				if (is_dir(file_stat.st_mode))
					ft_list_push_front
						(&dir_list, &(t_file){ft_strdup(full_file_name), file_stat}, sizeof(t_file));
				ft_list_push_front(&file_list, //oooohhhhhhhhhhhh should i check it
					&(t_file){ft_strdup(dp->d_name), file_stat}, sizeof(t_file));
			}
		}
		free(full_file_name);
	}
	file_list_to_arr(file_list, files);
	file_list_to_arr(dir_list, dirs);
	ft_lstdel(&file_list, del_list);
	ft_lstdel(&dir_list, del_list);
	closedir(dir_p);
	return (0);
}
