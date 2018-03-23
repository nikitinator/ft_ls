/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:04:38 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/08 14:32:19 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*c;

	c = s1;
	while (*s1)
		s1++;
	while (n > 0 && *s2 != '\0')
	{
		*s1++ = *s2++;
		n--;
	}
	*s1 = '\0';
	return (c);
}