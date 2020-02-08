/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:25:30 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 03:49:46 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		error(void)
{
	write(1, "ERROR\n", 6);
	exit(0);
}

void		ft_create_tlen(t_lem **tlen)
{
	if (!(*tlen = (t_lem *)malloc(sizeof(t_lem))))
		exit(0);
	(*tlen)->start_x = 2147483648;
	(*tlen)->start_y = 2147483648;
	(*tlen)->start_name = NULL;
	(*tlen)->start_num = -1;
	(*tlen)->end_x = 2147483648;
	(*tlen)->end_y = 2147483648;
	(*tlen)->end_name = NULL;
	(*tlen)->end_num = -1;
	(*tlen)->rooms = 0;
	(*tlen)->s_links = 0;
	(*tlen)->error = 0;
	(*tlen)->ant_count = 0;
	(*tlen)->lines = -1;
	(*tlen)->len = 1;
}

int			main(int ac, char *av[])
{
	char	*line;
	t_lem	*tlen;
	t_ant	**ants;
	t_top	**tops;
	int		c;

	c = 0;
	ft_create_tlen(&tlen);
	while (get_next_line(0, &line) > 0)
	{
		if (!(ft_strcmp(line, "\0")))
			error();
		ft_validation(line, &c, &tlen, &tops);
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
		if (tlen->error == 1)
			error();
	}
	write(1, "\n", 1);
	ft_map_change(tlen, tops);
	ants_attack(&tlen, tops, &ants);
	if (ac == 2)
		bonuses(&tlen, tops, av[1]);
	exit(0);
}
