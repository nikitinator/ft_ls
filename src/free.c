/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:37:44 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/03 18:25:01 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//void	free_dirs(t_dirs dirs)
//{
//	int		i;
//	
//	i = 0;
//	while(i < dirs.size)
//	{
//		closedir(dirs.arr[i].dir_p);
//		i++;
//	}
//	free(dirs.arr);
//}

void	free_dirs(t_files files)
{
	int		i;
	
	i = 0;
	if (files.arr)
		free(files.arr);
}

void	free_files(t_files files)
{
	int		i;
	
	i = 0;
	if (files.arr)
		free(files.arr);
}
