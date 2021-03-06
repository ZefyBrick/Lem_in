/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:28:12 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/28 18:23:07 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	long		n;
	int			c;

	n = 0;
	c = 1;
	while (*s == '\n' || *s == '\t' || *s == '\v' || *s == '\r' ||
			*s == '\f' || *s == 32)
		s += 1;
	if (*s == '-' && (*(s + 1) >= '0' && *(s + 1) <= '9'))
	{
		c = -1;
		s += 1;
	}
	else if (*s == '+' && *(s + 1) >= '0' && *(s + 1) <= '9')
		s += 1;
	while (*s >= '0' && *s <= '9')
		n = n * 10 + *(s)++ - '0';
	n *= c;
	if (n > 2147483647 || n < -2147483648)
	{
		write(1, "ERROR\n", 6);
		exit(0);
	}
	return (n);
}
