/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:11:57 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/08 20:27:50 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_digit(int n, int col)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		i = 2;
		if (n == -2147483648)
			n += 1;
		n = -n;
	}
	while (n / col > 0)
	{
		i++;
		n /= col;
	}
	return (i);
}
