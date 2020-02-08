/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_level.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:27:29 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 03:24:02 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_level_end(t_lem **tlen, t_top **tops, int *s)
{
	int		j;
	int		r;

	j = -1;
	r = -1;
	while (++j < ROOMS)
	{
		if (MAP1[E_NUM][j] == 1 && tops[j]->stack == 0)
		{
			tops[j]->e_turn = -1;
			tops[j]->stack = 1;
			s[++r] = j;
		}
	}
	return (r);
}

void		ft_stack_null(t_lem **tlen, t_top **tops)
{
	int		c;

	c = -1;
	while (++c < ROOMS)
		if (tops[c]->stack == 1)
			tops[c]->stack = 0;
}

void		ft_end_level(t_lem **tlen, t_top **tops)
{
	int		s[ROOMS];
	int		c;
	int		j;
	int		r;
	int		i;

	ft_create_stack(s, tlen, &c, &i);
	r = ft_level_end(tlen, tops, s);
	while (s[++i] != -1)
	{
		j = -1;
		while (++j < ROOMS)
		{
			if (MAP1[s[i]][j] == 1 && tops[j]->stack == 0 &&
			j != E_NUM && s[i] != S_NUM)
			{
				if (c == tops[s[i]]->e_turn)
					--c;
				tops[j]->e_turn = c;
				tops[j]->stack = 1;
				s[++r] = j;
			}
		}
	}
	ft_stack_null(tlen, tops);
}
