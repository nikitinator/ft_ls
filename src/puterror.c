/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:45:52 by snikitin          #+#    #+#             */
/*   Updated: 2018/05/06 20:18:22 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*get_name_from_path(char *str)
{
	char	*result;

	result = ft_strrchr(str, '/');
	if (result)
	{
		result = ft_strdup(result + 1);
		return (result);
	}
	return (ft_strdup(str));
}

void		puterror_perm_denied(char *dir_path)
{
	char *file_name;

	file_name = get_name_from_path(dir_path);
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(file_name, 2);
	free(file_name);
	ft_putendl_fd(": Permission denied", 2);
}

void		puterror_no_key(char key)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(key, 2);
	ft_putchar_fd('\n', 2);
}

void		puterror_no_file(char *file_name)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putendl_fd(": No such file or directory", 2);
}
