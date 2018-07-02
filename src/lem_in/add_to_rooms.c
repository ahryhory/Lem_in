/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:03:53 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/03 12:03:55 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_to_rooms(t_rooms **rooms, char *name, int *coord, int index)
{
	t_rooms	*tmp;

	if (*rooms == NULL)
	{
		*rooms = (t_rooms *)malloc(sizeof(t_rooms));
		(*rooms)->name = name;
		(*rooms)->coord_1 = coord[0];
		(*rooms)->coord_2 = coord[1];
		free(coord);
		(*rooms)->index = index;
		(*rooms)->next = NULL;
	}
	else
	{
		tmp = *rooms;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (t_rooms *)malloc(sizeof(t_rooms));
		tmp->next->name = name;
		tmp->next->coord_1 = coord[0];
		tmp->next->coord_2 = coord[1];
		free(coord);
		tmp->next->index = index;
		tmp->next->next = NULL;
	}
}
