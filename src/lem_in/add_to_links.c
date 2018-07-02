/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:32:44 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/03 12:32:45 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	find_index(t_farm *farm, char **link, int num)
{
	t_rooms *rooms;

	rooms = farm->rooms;
	while (rooms)
	{
		if (ft_strequ(rooms->name, link[num]))
			return (rooms->index);
		rooms = rooms->next;
	}
	return (0);
}

static void	push_back(t_links **links, t_farm *farm, char **link)
{
	t_links	*tmp;

	tmp = *links;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_links *)malloc(sizeof(t_links));
	tmp->next->link = link;
	tmp->next->index_1 = find_index(farm, link, 0);
	tmp->next->index_2 = find_index(farm, link, 1);
	tmp->next->next = NULL;
}

int			add_to_links(t_links **links, t_farm *farm, char **link)
{
	if (link != NULL)
	{
		if (*links == NULL)
		{
			*links = (t_links *)malloc(sizeof(t_links));
			(*links)->link = link;
			(*links)->index_1 = find_index(farm, link, 0);
			(*links)->index_2 = find_index(farm, link, 1);
			(*links)->next = NULL;
		}
		else
			push_back(links, farm, link);
	}
	else
		return (-1);
	return (1);
}
