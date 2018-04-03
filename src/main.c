/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:00:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/03 18:51:13 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_params	params;
	t_files		dirs;
	t_files		files;

	(void)argc;
	if (get_arg_keys(&argv, &params))
		return (1);
	params.first = 1;//
	if (get_arg_files(argv, &params, &dirs, &files))
		return (1);
	list_files(files, NULL, params);
	if (files.size)
		params.first = 0;//
	if (dirs.size == 1)
	{
		if (params.first == 0)
		{
			params.first = 1;
			print_dir_name(dirs.arr[0].name, &params.first);
		}
		params.first = 0;
		if (list_dir(dirs.arr[0], params))
			puterror_perm_denied("");
		free(dirs.arr[0].name);
	}
	else
		list_dirs(dirs, params);
	free_dirs(dirs);
	free_files(files);
	return (0);
}
