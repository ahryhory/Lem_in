/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:01:36 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/04 14:01:37 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_min(int **matr, int start_end[2])
{
	int		i;
	int		end;
	int		min;

	end = start_end[1];
	i = 1;
	while (matr[end][i] != -1 && matr[end][i] == 0)
		i++;
	min = matr[end][i];
	i = 1;
	while (matr[end][i] != -1)
	{
		if (matr[end][i] < min && matr[end][i] != 0)
			min = matr[end][i];
		i++;
	}
	return (min);
}

void		next_step(int ***p_matr, int start_end[2], int **way, int j)
{
	int		**matr;
	int		end;
	int		i;
	int		min;

	matr = *p_matr;
	min = get_min(matr, start_end);
	end = start_end[1];
	i = 1;
	while (matr[end][i] != -1)
	{
		if (matr[end][i] == min)
			break ;
		i++;
	}
	(*way)[j] = i;
	(*way)[j + 1] = -1;
	if (i != start_end[0])
	{
		start_end[1] = i;
		next_step(p_matr, start_end, way, j + 1);
	}
}
