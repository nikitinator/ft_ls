/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:44:57 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/22 18:12:53 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_files(t_file *file_1, t_file *file_2)
{
	t_file file_temp;

	file_temp = *file_1;
	*file_1 = *file_2;
	*file_2 = file_temp;
}

void	swap_dirs(t_dir *dir_1, t_dir *dir_2)
{
	t_dir dir_temp;

	dir_temp = *dir_1;
	*dir_1 = *dir_2;
	*dir_2 = dir_temp;
}
