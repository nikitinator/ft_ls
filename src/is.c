/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:39:50 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/27 17:17:14 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_blck_dev(mode_t st_mode)
{
	return ((st_mode & S_IFMT) == S_IFBLK);
}

int		is_char_dev(mode_t st_mode)
{
	return ((st_mode & S_IFMT) == S_IFCHR);
}
int		is_dir(mode_t st_mode)
{
	return ((st_mode & S_IFMT) == S_IFDIR);
}

int		is_sym_link(mode_t st_mode)
{
	return ((st_mode & S_IFMT) == S_IFLNK);
}

int		is_hidden(char *name)
{
	return (*name == '.');
}
