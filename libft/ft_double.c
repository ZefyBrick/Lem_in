/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:06:40 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/09 17:48:59 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_double(char *s, char c)
{
	int		i;
	int		j;

	i = -1;
	j = (int)ft_strlen(s) - 1;
	while (++i < j)
	{
		if (s[i] == c && s[i + 1] == c)
			return (0);
	}
	return (1);
}
