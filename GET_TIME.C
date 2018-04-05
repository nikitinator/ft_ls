/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:09:45 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/05 19:16:42 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <time.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char *time_str;
	time_t time;
	struct stat f_stat;

	if (argc == 2)
	{
		lstat(argv[1], &f_stat);
		time_str = ctime(&f_stat.st_mtime);
		printf("\n");
		printf("%s", time_str);
		printf("\n");
	}
	return (0);
}
