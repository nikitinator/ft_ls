/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:00:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/30 16:12:36 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_params	params;
	t_files		dirs;
	t_files		files;

	if (get_arg_keys(argc, argv, &params))
		return (-1);
	if (get_arg_files(argc, argv, &dirs, &files))
		return (-1);
	list_files(files, NULL, params);
	if (files.size)
		params.first = 0;
	if (dirs.size == 1)
	{
		params.first = 0;
		if (list_dir(dirs.arr[0], params))
			puterror_perm_denied("");
		free(dirs.arr[0].name);
	}
	else
	{
		list_dirs(dirs, params);
	}
	free_dirs(dirs);
	free_files(files);
	return (0);
}
