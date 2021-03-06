/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:13:55 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/27 16:48:47 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		red(void)
{
	write(1, "\033[0;31m", 7);
}

void		green(void)
{
	write(1, "\033[1;32m", 7);
}

void		reset(void)
{
	write(1, "\033[0m", 4);
}

void		cyan(void)
{
	write(1, "\033[1;36m", 7);
}
