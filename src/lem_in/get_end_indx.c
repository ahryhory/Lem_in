/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_end_indx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:58:18 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/05 12:58:20 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	get_end_indx(t_farm *farm)
{
	t_rooms	*rooms;
	int		end;

	rooms = farm->rooms;
	while (rooms)
	{
		if (ft_strequ(rooms->name, farm->end))
			end = rooms->index;
		rooms = rooms->next;
	}
	return (end);
}
