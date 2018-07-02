/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:43:25 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/02 17:43:31 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	count_splt_room(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	check_unic(char *room_name, t_farm **p_farm)
{
	t_rooms	*rooms;

	rooms = (*p_farm)->rooms;
	while (rooms)
	{
		if (ft_strequ(rooms->name, room_name))
		{
			free(room_name);
			ft_exit(p_farm);
		}
		rooms = rooms->next;
	}
}

char		*check_rooms(char *room, t_farm **p_farm)
{
	char	**splt_room;
	char	*room_name;

	splt_room = ft_strsplit(room, ' ');
	if (splt_room == NULL || count_splt_room(splt_room) != 3 ||
		splt_room[0][0] == 'L')
	{
		ft_clr(&splt_room);
		ft_exit(p_farm);
	}
	room_name = ft_strdup(splt_room[0]);
	ft_clr(&splt_room);
	check_unic(room_name, p_farm);
	return (room_name);
}
