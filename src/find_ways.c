/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 22:44:05 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/29 01:54:42 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_i_like_it(t_lem **tlen, int d, int c, t_top **tops)
{
	int		j;

	j = -1;
	while (++j < ROOMS)
		if ((MAP[d][j] == 1 && tops[j]->stop != c))
			return (0);
	return (1);
}

void		ft_clear(t_top **tops, int c, int j)
{
	int		i;

	i = -1;
	while (tops[j]->book[++i] != c)
		;
	tops[j]->book[i] = -1;
}

void		ft_another_tail(t_lem **tlen, t_top **tops, int *j, int c)
{
	if ((*j) != 0 && (MAP[WAY[c][(*j)]][WAY[c][(*j)]] == -2 \
	|| tops[WAY[c][(*j)]]->links >= 3))
	{
		ft_clear(tops, c, WAY[c][(*j)]);
		MAP[WAY[c][(*j) - 1]][WAY[c][(*j)]] = -3;
		WAY[c][(*j)--] = -1;
	}
	while ((*j) > 0 && tops[WAY[c][((*j))]]->links < 3)
	{
		MAP[WAY[c][(*j) - 1]][WAY[c][(*j)]] = -3;
		ft_clear(tops, c, WAY[c][(*j)]);
		tops[WAY[c][(*j)]]->stop = -1;
		WAY[c][(*j)--] = -1;
	}
	if ((*j) == 0 && ft_i_like_it(tlen, WAY[c][(*j)], c, tops))
	{
		ft_clear(tops, c, WAY[c][(*j)]);
		tops[WAY[c][(*j)]]->stop = -1;
		WAY[c][(*j)] = -1;
		return ;
	}
	ft_the_best_way2(tlen, tops, j, c);
}
