/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms_level.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:20:33 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 03:44:39 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_create_stack(int *s, t_lem **tlen, int *c, int *i)
{
	int		j;

	j = -1;
	while (++j < ROOMS)
		s[j] = -1;
	*c = -1;
	*i = -1;
}

int			ft_level_one(t_lem **tlen, t_top **tops, int *s)
{
	int		j;
	int		r;

	j = -1;
	r = -1;
	while (++j < ROOMS)
	{
		if (MAP[S_NUM][j] == 1 && tops[j]->stack == 0)
		{
			tops[j]->turn = 1;
			tops[j]->stack = 1;
			s[++r] = j;
		}
	}
	return (r);
}

void		ft_tops_c(t_top **tops, int j, int c)
{
	tops[j]->turn = c;
	tops[j]->stack = 1;
}

void		ft_tops_c1(t_top **tops, int *s, int i, int *c)
{
	if (*c == tops[s[i]]->turn)
		++(*c);
}

void		ft_level(t_lem **tlen, t_top **tops)
{
	int		s[ROOMS];
	int		c;
	int		j;
	int		r;
	int		i;

	ft_create_stack(s, tlen, &c, &i);
	c = 1;
	r = ft_level_one(tlen, tops, s);
	while (s[++i] != -1)
	{
		j = -1;
		while (++j < ROOMS)
		{
			if (MAP[s[i]][j] == 1 && tops[j]->stack == 0 && \
			j != S_NUM && s[i] != E_NUM)
			{
				ft_tops_c1(tops, s, i, &c);
				ft_tops_c(tops, j, c);
				s[++r] = j;
			}
		}
	}
	M_LVL = tops[s[r]]->turn;
	ft_stack_null(tlen, tops);
}
