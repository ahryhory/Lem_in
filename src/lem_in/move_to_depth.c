/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_depth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:14:17 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/04 12:14:19 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_1(t_links *links, int **matr, int curent, int depth)
{
	if (links->index_1 == curent &&
		(depth < matr[links->index_1][links->index_2] ||
			matr[links->index_1][links->index_2] == 0))
		return (1);
	else
		return (0);
}

static int	check_2(t_links *links, int **matr, int curent, int depth)
{
	if (links->index_2 == curent &&
		(depth < matr[links->index_1][links->index_2] ||
			matr[links->index_1][links->index_2] == 0))
		return (1);
	else
		return (0);
}

void		move_to_depth(t_farm *farm, int ***p_matr, int curent, int depth)
{
	int		**matr;
	t_links	*links;

	matr = *p_matr;
	links = farm->links;
	while (links)
	{
		if (check_1(links, matr, curent, depth))
		{
			matr[links->index_1][links->index_2] = depth;
			matr[links->index_2][links->index_1] = depth;
			move_to_depth(farm, &matr, links->index_2, depth + 1);
		}
		if (check_2(links, matr, curent, depth))
		{
			matr[links->index_1][links->index_2] = depth;
			matr[links->index_2][links->index_1] = depth;
			move_to_depth(farm, &matr, links->index_1, depth + 1);
		}
		links = links->next;
	}
	*p_matr = matr;
}
