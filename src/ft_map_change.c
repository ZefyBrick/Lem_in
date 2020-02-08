/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:17:29 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 03:36:58 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_copy_map(t_lem **tlen, int i)
{
	int		c;
	int		j;

	c = -1;
	j = -1;
	while (++c < i)
	{
		while (++j < i)
			MAP1[c][j] = MAP[c][j];
		j = -1;
	}
}

void		ft_delete_tupak_2(t_lem **tlen, t_top **tops, int j)
{
	int		i;

	i = ROOMS;
	while (--i)
	{
		if (MAP[j][i] == 1 && tops[j]->links == 1 && j != E_NUM && j != S_NUM)
		{
			MAP[i][j] = 0;
			MAP[j][i] = 0;
			tops[j]->links--;
			tops[i]->links--;
			if (tops[i]->links == 1)
				ft_delete_tupak_2(tlen, tops, i);
		}
	}
}

void		ft_delete_tupak(t_lem **tlen, t_top **tops)
{
	int		j;

	j = ROOMS;
	while (--j)
		ft_delete_tupak_2(tlen, tops, j);
}

void		ft_create_map1(t_lem **tlen)
{
	int		c;

	c = -1;
	if (ROOMS < 2)
		error();
	if (!(MAP1 = (int **)malloc(sizeof(int *) * ROOMS)))
		exit(0);
	while (++c < ROOMS)
		if (!(MAP1[c] = (int *)malloc(sizeof(int) * ROOMS)))
			exit(0);
}

void		ft_map_change(t_lem *tlen, t_top **tops)
{
	ft_start_end_nums(tlen, &tops);
	ft_start_end_links(&tlen, tops);
	ft_delete_tupak(&tlen, tops);
	ft_level(&tlen, tops);
	if (tops[(tlen->end_num)]->turn == 0)
		error();
	ft_create_map1(&tlen);
	ft_copy_map(&tlen, tlen->rooms);
	ft_end_level(&tlen, tops);
	ft_kill_loops(&tlen, tops);
	tlen->s_links = tops[tlen->start_num]->links;
	ft_the_shortest_way(&tlen, tops);
	ft_rew_way(&tlen, tops);
	ft_shortest_ways(&tlen, tops);
}
