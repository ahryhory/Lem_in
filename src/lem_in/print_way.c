/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:32:28 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/05 11:32:29 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void	rev_way(int **p_way)
{
	int	*way;
	int	size;
	int	tmp;
	int	mid;
	int	i;

	way = *p_way;
	size = 0;
	while (way[size] != -1)
		size++;
	mid = size / 2;
	size--;
	i = 0;
	while (i < mid)
	{
		tmp = way[i];
		way[i] = way[size];
		way[size] = tmp;
		i++;
		size--;
	}
}

static void	print_move(int i, char *name, t_farm *farm)
{
	if (!farm->first_move)
		ft_putstr(" ");
	ft_putstr("L");
	ft_putnbr(i + 1);
	ft_putstr("-");
	ft_putstr(name);
	farm->first_move = 0;
}

static void	find_room(t_farm *farm, int i, t_ants ants[], char **name)
{
	t_rooms	*rooms;

	rooms = farm->rooms;
	while (rooms)
	{
		if (rooms->index == ants[i].way[0])
		{
			if (!ft_strequ(*name, rooms->name))
			{
				*name = rooms->name;
				print_move(i, *name, farm);
				ants[i].way++;
				break ;
			}
		}
		rooms = rooms->next;
	}
}

static int	check_end(t_farm *farm, t_ants ants[])
{
	int		end;
	int		i;

	end = 1;
	i = 0;
	while (i < farm->ants)
	{
		if (ants[i].way[0] != -1)
			end = 0;
		i++;
	}
	return (end);
}

void		print_way(int *way, t_farm *farm)
{
	t_ants	ants[farm->ants];
	char	*name;
	int		i;
	int		end;

	name = NULL;
	rev_way(&way);
	i = 0;
	while (i < farm->ants)
		ants[i++].way = way + 1;
	end = 0;
	while (!end)
	{
		i = 0;
		farm->first_move = 1;
		while (i < farm->ants)
		{
			if (ants[i].way[0] != -1)
				find_room(farm, i, ants, &name);
			i++;
		}
		name = NULL;
		ft_putstr("\n");
		end = check_end(farm, ants);
	}
}
