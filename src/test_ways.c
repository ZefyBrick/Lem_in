/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:45:41 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/30 19:50:34 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_num_ways(t_lem **tlen)
{
	int		c;
	int		i;

	c = -1;
	if (!(VAR_PR = (int **)malloc(sizeof(int *) * S_LINKS)))
		exit(0);
	while (++c < S_LINKS)
	{
		i = -1;
		if (!(VAR_PR[c] = (int *)malloc(sizeof(int) * 10)))
			exit(0);
		while (++i < 10)
			VAR_PR[c][i] = -1;
	}
}

void		ft_clear_way(t_lem **tlen, t_top **tops, int c)
{
	int		i;

	i = 0;
	while (WAY[c][++i] != -1 && i <= IND)
	{
		tops[WAY[c][i]]->stop = -1;
		WAY[c][i] = -1;
	}
	IND = 0;
}

int			ft_test_ways(t_lem **tlen, int c)
{
	int		i;
	int		j;
	int		d;

	i = -1;
	while (++i < c)
	{
		d = -1;
		while (++d < IND)
		{
			j = -1;
			while (++j < WAY[i][101])
			{
				if (WAY[i][j] == WAY[c][d] && WAY[i][j] != S_NUM
				&& WAY[i][j] != E_NUM)
					return (WAY[i][j]);
			}
		}
	}
	return (-1);
}
