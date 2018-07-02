/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:32:53 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/03 12:32:54 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	count_splt_links(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	check_name_link(char **str, t_farm **p_farm)
{
	int		link_1;
	int		link_2;
	t_rooms	*rooms;

	link_1 = 0;
	link_2 = 0;
	rooms = (*p_farm)->rooms;
	if (ft_strequ(str[0], str[1]))
		return (0);
	while (rooms)
	{
		if (ft_strequ(str[0], rooms->name))
			link_1 = 1;
		if (ft_strequ(str[1], rooms->name))
			link_2 = 1;
		rooms = rooms->next;
	}
	if (link_1 && link_2)
		return (1);
	else
		return (0);
}

char		**check_links(char *str_links, t_farm **p_farm)
{
	char	**links;

	links = ft_strsplit(str_links, '-');
	if (links == NULL || count_splt_links(links) != 2)
	{
		ft_clr(&links);
		return (NULL);
	}
	if (!check_name_link(links, p_farm))
	{
		ft_clr(&links);
		return (NULL);
	}
	return (links);
}
