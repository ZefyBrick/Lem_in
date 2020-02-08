/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:35:49 by cdubuque          #+#    #+#             */
/*   Updated: 2019/08/19 19:37:27 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s2[i] == '\0')
		{
			while (i < n)
				s1[i++] = '\0';
		}
		else
		{
			s1[i] = s2[i];
			i++;
		}
	}
	s1[i] = '\0';
	return (s1);
}
