/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:45:52 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/30 21:18:27 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	puterror_no_key(char key)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(key, 2);
	ft_putchar_fd('\n', 2);
}
			
void		puterror_perm_denied(char *file_name)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putendl_fd(": Permission denied", 2);
}

void		puterror_no_file(char *file_name)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putendl_fd(": No such file or directory", 2);
}
