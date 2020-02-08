/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:08:24 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 03:47:39 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_create_ways(t_lem **tlen)
{
	int		c;
	int		i;

	c = -1;
	if (!(WAY = (int **)malloc(sizeof(int *) * S_LINKS)))
		exit(0);
	while (++c < S_LINKS)
	{
		i = -1;
		if (!(WAY[c] = (int *)malloc(sizeof(int) * (102))))
			exit(0);
		while (++i < 102)
			(*tlen)->ways[c][i] = -1;
	}
}

void		ft_stack_for_ways(t_lem **tlen, t_top **tops, int c)
{
	int		d;

	d = -1;
	while (++c < S_LINKS)
	{
		WAY[c][0] = S_NUM;
		ft_the_best_way(tlen, tops, c);
		if (IND >= 98)
			break ;
		if (c > 0)
		{
			d = ft_test_ways(tlen, c);
			if (d != -1)
				IND = 0;
		}
		if (WAY[c][0] != -1)
			ft_rewers_way(tlen, tops, c);
		ft_end_level(tlen, tops);
	}
}

void		ft_find_ways(t_lem **tlen, t_top **tops, int c)
{
	int		run;
	int		d;

	run = -1;
	d = -1;
	while (++d < ROOMS)
		if (MAP[S_NUM][d] == 1)
			MAP[d][S_NUM] = -1;
	d = -1;
	ft_stack_for_ways(tlen, tops, c);
}

void		ft_shortest_ways(t_lem **tlen, t_top **tops)
{
	ft_create_ways(tlen);
	ft_find_ways(tlen, tops, -1);
}
