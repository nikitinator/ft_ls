/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:00:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/22 15:56:48 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_params	params;
	t_dirs		dirs;
	t_files		files;

	if (get_arg_keys(argc, argv, &params))
		return (-1);
	if (get_arg_files(argc, argv, &dirs, &files)) //TODO pick more cool name (files)
		return (-1);
	list_files(files, params);
	if (dirs.size == 1)
		list_dir(dirs.arr[0], params);
	else
		list_dirs(dirs, params);
	free_dirs(dirs);
	free_files(files);
	return (0);
}