/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 22:36:09 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/27 22:38:25 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_three_good_bye(t_lem **tlen)
{
	int		c;
	int		d;

	d = -1;
	c = -1;
	while (++c < ROOMS)
		while (++d < ROOMS)
			if (MAP[c][d] == -3)
				MAP[c][d] = 1;
}

void		ft_close_way(t_lem **tlen, t_top **tops, int j, int c)
{
	MAP[WAY[c][j + 1]][WAY[c][j]] = 2;
	tops[WAY[c][j]]->links--;
	tops[WAY[c][j + 1]]->links--;
	MAP[WAY[c][j]][WAY[c][j + 1]] = 2;
	MAP1[WAY[c][j + 1]][WAY[c][j]] = 2;
	MAP1[WAY[c][j]][WAY[c][j + 1]] = 2;
}

void		ft_close_node(t_lem **tlen, int j, int c)
{
	MAP[WAY[c][j]][WAY[c][j]] = -2;
	MAP1[WAY[c][j]][WAY[c][j]] = -2;
}

void		ft_way_one(t_lem **tlen, int j, int c)
{
	MAP1[WAY[c][j + 1]][WAY[c][j]] = -1;
	MAP[WAY[c][j]][WAY[c][j + 1]] = -1;
}

void		ft_rewers_way(t_lem **tlen, t_top **tops, int c)
{
	int		j;
	int		f;

	j = 0;
	f = 0;
	if (tops[WAY[c][j]]->links > 2 && WAY[c][j] != E_NUM)
		ft_close_node(tlen, j, c);
	while (j < 101 && WAY[c][j + 1] != -1)
	{
		if (tops[WAY[c][j]]->links > 2 && WAY[c][j] != E_NUM)
			ft_close_node(tlen, j, c);
		if (MAP[WAY[c][j + 1]][WAY[c][j]] == -1)
			ft_close_way(tlen, tops, j, c);
		else
			ft_way_one(tlen, j, c);
		++j;
	}
}
