/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:17:51 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/02 12:17:53 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	create_farm(t_farm **p_farm)
{
	t_farm	*farm;

	farm = *p_farm;
	farm->start = NULL;
	farm->end = NULL;
	farm->data = NULL;
	farm->rooms = NULL;
	farm->links = NULL;
}

int			main(void)
{
	t_farm	*farm;
	char	*line;
	int		*way;

	farm = (t_farm *)malloc(sizeof(t_farm));
	create_farm(&farm);
	while (ft_get_next_line(0, &line))
		add_to_data(&(farm->data), line);
	parse_data(&farm);
	way = find_way(&farm);
	print_data(farm->data);
	print_way(way, farm);
	free(way);
	free_all_farm(&farm);
	return (0);
}
