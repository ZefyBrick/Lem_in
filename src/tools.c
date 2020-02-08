/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:48:13 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 02:40:25 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			write_room(t_lem **tlen, t_top **tops, int i, int j)
{
	green();
	write(1, "[", 1);
	reset();
	write(1, tops[WAY[j][i]]->name, ft_strlen(tops[WAY[j][i]]->name));
	green();
	write(1, "] ", 2);
	reset();
}

void			write_steps(t_lem **tlen, int c)
{
	write(1, " - ", 3);
	cyan();
	ft_putnbr(IND);
	reset();
}
