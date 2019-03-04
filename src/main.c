/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:47:35 by jallen            #+#    #+#             */
/*   Updated: 2019/03/04 19:42:26 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		msg_error(void)
{
	ft_fprintf(2, "map_error\n");
	return (0);
}

int		main(int ac, char **av)
{
	t_fl	filler;
	int		fd;
	int		ret;

	(void)ac;
	(void)av;
	ret = 0;
	fd = 0;
	filler.map = 0;
	filler.int_map = 0;
	if (ft_get_player(&ret, &fd, &filler) == 0)
		return (msg_error());
	else if (ft_parsing(&ret, &fd, &filler) == 1)
		ft_heatmap(&filler);
	else
		return (msg_error());
	free_intray(filler.int_map, filler.axis.y);
	return (0);
}
