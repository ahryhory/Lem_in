/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_indx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:58:11 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/05 12:58:12 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	get_start_indx(t_farm *farm)
{
	t_rooms	*rooms;
	int		start;

	rooms = farm->rooms;
	while (rooms)
	{
		if (ft_strequ(rooms->name, farm->start))
			start = rooms->index;
		rooms = rooms->next;
	}
	return (start);
}
