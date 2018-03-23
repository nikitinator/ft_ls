/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:33:44 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/23 20:55:14 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_dir_name(char *name)
{
	ft_putstr(name);
	ft_putendl(":");
}

void	list_dir_normal(t_file dir, t_params params)
{
	t_files	files;

	ft_bzero(&files, sizeof(t_files));
	get_files_from_dir(dir, &files, params.show_hidden); //do i need to send params there?
	list_files(files, ft_strdup(dir.name), params);
	free_files(files);
	free(dir.name);
}

void	list_dir_recurs(t_file dir, t_params params) //ne otpravlyai ves params
{	
	t_files	files;
	t_files	dirs;

	ft_bzero(&files, sizeof(t_files));
	ft_bzero(&dirs, sizeof(t_files));
	get_files_dirs_from_dir(dir, &files, &dirs, params.show_hidden); //do i need to send params there?
	list_files(files, ft_strdup(dir.name),  params);
	list_dirs(dirs, params);
	free_files(files);
	free_dirs(dirs);
	free(dir.name);
}

void	list_dir(t_file dir, t_params params) //ne otpravlyai ves params
{	
	if (params.recursive)
		list_dir_recurs(dir, params);
	else 
		list_dir_normal(dir, params);
}

void	list_dirs(t_files dirs, t_params params)
{
	int		i;

	if (dirs.size == 0)
		return ;
	sort_files(dirs, params.time_modif);
	if (params.reverse)
		reverse_files(dirs);
	i = 0;
	while (i < dirs.size)
	{
		print_dir_name(dirs.arr[i].name);
		list_dir(dirs.arr[i], params);
		i++;
	}
}
