/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:47:35 by jallen            #+#    #+#             */
/*   Updated: 2019/03/08 12:00:14 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		msg_error(void)
{
	ft_fprintf(2, "map_error\n");
	return (0);
}

int		main(void)
{
	t_fl	filler;

	filler.vef_piece = 0;
	filler.score = 0;
	filler.map = 0;
	filler.int_map = 0;
	if (ft_get_player(&filler) == 1)
		ft_parsing(&filler);
	return (0);
}
