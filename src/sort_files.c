/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:12:39 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/22 18:30:22 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		file_cmp_lexicograph(t_file file_1, t_file file_2)
{
	return (ft_strcmp(file_1.name, file_2.name));
}

int		file_cmp_time_modif(t_file file_1, t_file file_2)
{
	return (file_2.f_stat.st_mtime - file_1.f_stat.st_mtime);
}

void	quick_sort_files(t_file *arr, t_uint size,
		int (*file_cmp)(t_file file_1, t_file file_2))
{
	t_uint	i;
	t_uint	last;

	if (size <= 1)
		return ;
	swap_files(arr + 0, arr + size/2);
	last = 0;
	i = 1;
	while (i < size)
	{
		if ((*file_cmp)(arr[i], arr[0]) < 0)
		{
			last++;
			swap_files(arr + i, arr + last);
		}
		i++;
	}
	swap_files(arr + 0, arr + last);
	quick_sort_files(arr, last, file_cmp);
	quick_sort_files(arr + last + 1, size - last - 1, file_cmp);
}

void	sort_files(t_files files, char time_modif)
{
	(void)files;
	if (time_modif)
		quick_sort_files(files.arr, files.size, file_cmp_time_modif);
	else
		quick_sort_files(files.arr, files.size, file_cmp_lexicograph);
}
