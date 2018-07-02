/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:35:48 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/03 15:35:49 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	create_matr(int ***p_matr, int size)
{
	int		**matr;
	int		i;
	int		j;

	matr = *p_matr;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j + 1 == size || i + 1 == size)
				matr[i][j] = -1;
			else if (j == 0)
				matr[i][j] = i;
			else if (i == 0)
				matr[i][j] = j;
			else
				matr[i][j] = 0;
			j++;
		}
		i++;
	}
	*p_matr = matr;
}

static void	find_depth(t_farm *farm, int ***p_matr)
{
	int		**matr;
	int		depth;
	int		start;

	matr = *p_matr;
	start = get_start_indx(farm);
	depth = 1;
	move_to_depth(farm, &matr, start, depth);
	*p_matr = matr;
}

static int	*get_way(t_farm *farm, int ***p_matr)
{
	int		**matr;
	int		start_end[2];
	int		i;
	int		*way;

	matr = *p_matr;
	start_end[0] = get_start_indx(farm);
	start_end[1] = get_end_indx(farm);
	way = (int *)malloc(sizeof(int) * 100);
	i = 0;
	way[i] = start_end[1];
	way[i + 1] = -1;
	next_step(p_matr, start_end, &way, i + 1);
	free_matr(&matr);
	return (way);
}

static void	check_way(t_farm **p_farm, int ***p_matr)
{
	int		**matr;
	int		end;
	int		i;

	matr = *p_matr;
	end = get_end_indx(*p_farm);
	i = 1;
	while (matr[end][i] != -1)
	{
		if (matr[end][i] != 0)
			break ;
		i++;
	}
	if (matr[end][i] == -1)
	{
		free_matr(&matr);
		ft_exit(p_farm);
	}
}

int			*find_way(t_farm **p_farm)
{
	t_farm	*farm;
	t_rooms	*rooms;
	int		size;
	int		i;
	int		**matr;

	farm = *p_farm;
	rooms = farm->rooms;
	size = 0;
	while (rooms)
	{
		size++;
		rooms = rooms->next;
	}
	size += 2;
	matr = (int **)malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
		matr[i++] = (int *)malloc(sizeof(int) * size);
	create_matr(&matr, size);
	find_depth(*p_farm, &matr);
	check_way(p_farm, &matr);
	return (get_way(farm, &matr));
}
