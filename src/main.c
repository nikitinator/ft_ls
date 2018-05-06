/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:00:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/05/06 20:00:00 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_errors(t_files errors)
{
	size_t	i;

	i = 0;
	while (i < errors.size)
	{
		puterror_no_file(errors.arr[i].name);
		i++;
	}
}

static void	list_arg_files(t_arg arg_f, t_params *par)
{
	sort_files(arg_f.errors, 0);
	print_errors(arg_f.errors);
	par->first_time = 1;
	list_files(arg_f.files, NULL, *par);
	if (arg_f.files.size)
		par->first_time = 0;
	if (arg_f.dirs.size == 1)
	{
		if (arg_f.files.size || arg_f.errors.size)
			print_dir_name(arg_f.dirs.arr[0].name, &par->first_time);
		par->first_time = 0;
		if (list_dir(arg_f.dirs.arr[0], *par))
			puterror_perm_denied(arg_f.dirs.arr[0].name);
	}
	else
	{
		if (arg_f.files.size && arg_f.dirs.size)
			par->first_time = 0;
		list_dirs(arg_f.dirs, *par);
	}
}

int			main(int argc, char **argv)
{
	t_params	params;
	t_arg		arg_files;

	(void)argc;
	if (get_arg_keys(&argv, &params))
		return (1);
	if (get_arg_files(argv, params, &arg_files))
		return (1);
	list_arg_files(arg_files, &params);
	free_files(arg_files.dirs);
	free_files(arg_files.files);
	free_files(arg_files.errors);
	return (0);
}
