/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 21:06:56 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/22 13:27:31 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_params_key(char *key, t_params *par)
{
	short	i;

	i = 1;
	while (key[i])
	{
		if (key[i] == 'r')
			par->reverse = 1;
		else if (key[i] == 'l')
			par->long_format = 1;
		else if (key[i] == 'a')
			par->show_hidden = 1;
		else if (key[i] == 'R')
			par->recursive = 1;
		else if (key[i] == 't')
			par->time_modif = 1;
		else
		{
			ft_putstr_fd("ls: illegal option -- ", 2); //ensure the fd
			ft_putchar_fd(key[i], 2);
			ft_putchar_fd('\n', 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int			get_arg_keys(int argc, char **argv, t_params *params)
{
	t_byte	i;

	ft_bzero(params, sizeof(t_params));
	i = 1;
	while (i < argc && *(argv[i]) == '-')
	{
		if (get_params_key(argv[i], params))
		{
			print_usage();
			return (-1);
		}
		i++;
	}
	return (0);
}
