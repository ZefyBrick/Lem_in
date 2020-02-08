/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_the_shortest_way.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:17:37 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 03:47:12 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_the_best_way2(t_lem **tlen, t_top **tops, int (*j), int c)
{
	int		d;

	d = -1;
	while (++d < ROOMS)
	{
		if (MAP[WAY[c][(*j)]][d] == 1)
		{
			if (tops[d]->stop != c)
			{
				if (WAY[c][(*j) + 1] == -1)
					WAY[c][(*j) + 1] = d;
				else if (tops[d]->e_turn > tops[WAY[c][(*j) + 1]]->e_turn)
					WAY[c][(*j) + 1] = d;
				else if (tops[d]->e_turn == tops[WAY[c][(*j) + 1]]->e_turn \
				&& tops[d]->stop == -1 && tops[WAY[c][(*j) + 1]]->stop != -1)
					WAY[c][(*j) + 1] = d;
			}
		}
	}
	if (WAY[c][(*j) + 1] == -1)
		ft_another_tail(tlen, tops, j, c);
}

void		ft_null_number(t_lem **tlen, t_top **tops, int c)
{
	int		d;

	d = -1;
	while (++d < ROOMS)
		if (MAP[S_NUM][d] == 1)
			if (WAY[c][1] == -1 || tops[d]->e_turn > tops[WAY[c][1]]->e_turn)
				WAY[c][1] = d;
	tops[WAY[c][1]]->book[0] = c;
	tops[WAY[c][1]]->stop = c;
}

void		ft_the_best_way(t_lem **tlen, t_top **tops, int c)
{
	int		j;
	int		i;

	ft_null_number(tlen, tops, c);
	j = 0;
	MAP[S_NUM][WAY[c][1]] = -1;
	while (WAY[c][++j] != E_NUM && j < 100)
	{
		i = -1;
		ft_the_best_way2(tlen, tops, &j, c);
		if (WAY[c][j + 1] == -1)
		{
			ft_three_good_bye(tlen);
			IND = 0;
			return ;
		}
		tops[WAY[c][j + 1]]->stop = c;
		while (tops[WAY[c][j + 1]]->book[++i] != -1)
			;
		tops[WAY[c][j + 1]]->book[i] = c;
	}
	IND = j;
}
