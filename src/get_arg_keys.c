/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 21:06:56 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/30 21:04:07 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_params_key(char *key, t_params *par)
{
	short	i;
	short	hyphen_count;

	i = 0;
	hyphen_count = 1;
	while (key[++i])
	{
		if (hyphen_count > 2)
		{
			puterror_no_key('-');
			return (-1);
		}
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
		else if (key[i] == '-') //---
			return (0);
		else if (key[i] == '1')
			;
		else
		{
			puterror_no_key(key[i]);
			return (-1);
		}
	}
	return (0);
}

int			get_arg_keys(int argc, char **argv, t_params *params)
{
	int		i;

	ft_bzero(params, sizeof(t_params));
	i = 1;
	while (i < argc && *(argv[i]) == '-')
	{
		if (ft_strequ(argv[i], "--"))
			return (0);
		if (get_params_key(argv[i], params))
		{
			print_usage();
			return (-1);
		}
		i++;
	}
	params->first = 1;
	return (0);
}
