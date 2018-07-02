/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_farm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:01:07 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/02 17:12:29 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	free_data(t_farm **farm)
{
	t_data		*data;

	data = (*farm)->data;
	while (data != NULL)
	{
		free(data->line);
		free(data);
		data = data->next;
	}
}

static void	free_rooms(t_farm **farm)
{
	t_rooms		*rooms;

	rooms = (*farm)->rooms;
	while (rooms != NULL)
	{
		free(rooms->name);
		free(rooms);
		rooms = rooms->next;
	}
}

static void	free_links(t_farm **farm)
{
	t_links		*links;

	links = (*farm)->links;
	while (links != NULL)
	{
		ft_clr(&(links->link));
		free(links);
		links = links->next;
	}
}

void		free_all_farm(t_farm **farm)
{
	if ((*farm)->start != NULL)
		free((*farm)->start);
	if ((*farm)->end != NULL)
		free((*farm)->end);
	free_data(farm);
	free_rooms(farm);
	free_links(farm);
}
