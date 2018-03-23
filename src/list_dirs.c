/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:33:44 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/22 18:43:14 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_dir_name(char *name)
{
	ft_putstr(name);
	ft_putendl(":");
}

void	list_dir_normal(t_dir dir, t_params params)
{
	t_files	files;

	ft_bzero(&files, sizeof(t_files));
	get_files_from_dir(dir, &files, params); //do i need to send params there?
	list_files(files, params);
	free_files(files);
	free(dir.name);
}

void	list_dir_recurs(t_dir dir, t_params params) //ne otpravlyai ves params
{	
	t_files	files;
	t_dirs	dirs;

	ft_bzero(&files, sizeof(t_files));
	ft_bzero(&dirs, sizeof(t_dirs));
	get_files_dirs_from_dir(dir, &files, &dirs, params); //do i need to send params there?
	list_files(files, params);
	list_dirs(dirs, params);
	free_files(files);
	free_dirs(dirs);
	free(dir.name);
}

void	list_dir(t_dir dir, t_params params) //ne otpravlyai ves params
{	
	if (params.recursive)
		list_dir_recurs(dir, params);
	else 
		list_dir_normal(dir, params);
}

void	list_dirs(t_dirs dirs, t_params params)
{
	int		i;

	if (dirs.size == 0)
		return ;
	if (params.reverse)
		reverse_dirs(dirs);
	i = 0;
	while (i < dirs.size)
	{
		print_dir_name(dirs.arr[i].name);
		list_dir(dirs.arr[i], params);
		i++;
	}
}
