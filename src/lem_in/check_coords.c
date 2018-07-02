/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:10:12 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/05 16:10:13 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	count_splt(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	check_unic(int *coord, t_farm **p_farm)
{
	t_rooms	*rooms;

	rooms = (*p_farm)->rooms;
	while (rooms)
	{
		if (rooms->coord_1 == coord[0] && rooms->coord_2 == coord[1])
		{
			free(coord);
			ft_exit(p_farm);
		}
		rooms = rooms->next;
	}
}

static int	check_coord(char *coord, char *str)
{
	unsigned long long	num;
	int					neg;

	num = 0;
	neg = 0;
	if (*coord == '+' || *coord == '-')
		coord++;
	while (*coord)
	{
		if (!ft_isdigit(*coord))
			return (1);
		coord++;
	}
	if (*str == '-')
		neg = 1;
	if (*str == '+' || *str == '-')
		str++;
	if (ft_strlen(str) > 10)
		return (1);
	while (*str)
		num = num * 10 + (*str++ - '0');
	if (num > 2147483647 || (neg && num > 2147483648))
		return (1);
	return (0);
}

int			*check_coords(char *room, t_farm **p_farm)
{
	char	**splt;
	int		*coord;

	coord = (int *)malloc(sizeof(int) * 2);
	splt = ft_strsplit(room, ' ');
	if (splt == NULL || count_splt(splt) != 3 ||
		splt[0][0] == 'L' || check_coord(splt[1], splt[1]) ||
		check_coord(splt[2], splt[2]))
	{
		ft_clr(&splt);
		ft_exit(p_farm);
	}
	coord[0] = ft_atoi(splt[1]);
	coord[1] = ft_atoi(splt[2]);
	ft_clr(&splt);
	check_unic(coord, p_farm);
	return (coord);
}
