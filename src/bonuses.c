/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:09:48 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 02:40:03 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			bonuses(t_lem **tlen, t_top **tops, char *av)
{
	if (av[0] == '-')
	{
		if (ft_strchr(av, 'l'))
			write_lines(tlen);
		if (ft_strchr(av, 's'))
			write_with_steps(tlen, tops);
		else if (ft_strchr(av, 'w'))
			write_ways(tlen, tops);
	}
}

void			write_lines(t_lem **tlen)
{
	write(1, "\n", 1);
	write(1, "number of lines : ", 18);
	green();
	ft_putnbr((*tlen)->lines);
	write(1, "\n\n", 2);
	reset();
}

void			write_ways(t_lem **tlen, t_top **tops)
{
	int		i;
	int		c;

	c = -1;
	write(1, "\n", 1);
	while (++c < S_LINKS)
	{
		i = -1;
		if (IND != 0 && IND != -1)
		{
			while (WAY[c][++i] != -1 && i < 101)
				write_room(tlen, tops, i, c);
			write(1, "\n\n", 2);
		}
	}
	write(1, "\n", 1);
}

void			write_with_steps(t_lem **tlen, t_top **tops)
{
	int		i;
	int		c;

	c = -1;
	write(1, "\n", 1);
	while (++c < S_LINKS)
	{
		i = -1;
		if (IND != 0 && IND != -1)
		{
			while (WAY[c][++i] != -1 && i < 101)
				write_room(tlen, tops, i, c);
			write_steps(tlen, c);
			write(1, "\n\n", 2);
		}
	}
	write(1, "\n", 1);
}
