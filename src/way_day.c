/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_day.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:16:16 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 03:47:52 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_kill_loops(t_lem **tlen, t_top **tops)
{
	int		c;
	int		j;

	c = -1;
	while (++c < ROOMS)
	{
		if (tops[c]->e_turn == 0 && c != E_NUM)
		{
			j = -1;
			tops[c]->links = 0;
			while (++j < ROOMS)
			{
				if (MAP[c][j] == 1)
				{
					MAP[c][j] = 0;
					MAP[j][c] = 0;
					if (tops[j]->links > 0)
						tops[j]->links--;
				}
			}
		}
	}
}

void		ft_rew_way(t_lem **tlen, t_top **tops)
{
	int		tmp;
	int		i;
	int		j;

	tmp = 0;
	j = -1;
	i = tops[E_NUM]->turn - 1;
	if (i > 0)
	{
		while (j < i)
		{
			tmp = M_WAY[i];
			M_WAY[i--] = M_WAY[++j];
			M_WAY[j] = tmp;
		}
	}
	while (M_WAY[i] != S_NUM)
		++i;
	M_WAY[i] = -1;
}

void		ft_the_shortest_way2(t_lem **tlen, t_top **tops, int *j)
{
	int		c;

	c = -1;
	while (++c < ROOMS)
	{
		if (MAP[M_WAY[*j]][c] == 1)
		{
			if (tops[c]->turn == tops[M_WAY[*j]]->turn - 1)
			{
				M_WAY[++(*j)] = c;
				break ;
			}
		}
	}
}

void		ft_the_shortest_way(t_lem **tlen, t_top **tops)
{
	int		c;
	int		j;

	c = -1;
	j = -1;
	if (!(M_WAY = (int *)malloc(sizeof(int) * (tops[E_NUM]->turn + 1))))
		exit(0);
	M_WAY[++j] = E_NUM;
	while (++c < ROOMS)
	{
		if (MAP[E_NUM][c] == 1)
		{
			if (tops[c]->turn == tops[E_NUM]->turn - 1)
			{
				M_WAY[++j] = c;
				break ;
			}
		}
	}
	while (M_WAY[j] != S_NUM)
		ft_the_shortest_way2(tlen, tops, &j);
}
