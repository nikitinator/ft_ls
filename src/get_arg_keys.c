/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 21:06:56 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/03 18:04:35 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	get_params_key(char *key, t_params *par)
{
	short	i;

	i = 0;
	while (key[++i])
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
		else if (key[i] == '1')
			;
		else
			return (key[i]);
	}
	return (0);
}

int			get_arg_keys(char ***argv, t_params *params)
{
	int		i;
	char	invalid_char;
	char	**av;

	av = *argv;
	ft_bzero(params, sizeof(t_params));
	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		if (ft_strequ(av[i], "-"))
		{
			break;
		}
		if (ft_strequ(av[i], "--"))
		{
			i++;
			break;
		}
		if ((invalid_char = get_params_key(av[i], params)))
		{
			puterror_no_key(invalid_char);
			print_usage();
			return (1);
		} 
		i++;
	}
	*argv = av + i;
	return (0);
}
