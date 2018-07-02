/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbr_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:30:55 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/02 13:48:46 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	arrtoint(char *str, t_farm **farm)
{
	unsigned long long	num;

	num = 0;
	if (*str == '+')
		str++;
	if (ft_strlen(str) > 10)
		ft_exit(farm);
	while (*str)
		num = num * 10 + (*str++ - '0');
	if (num == 0 || num > 2147483647)
		ft_exit(farm);
	return ((int)num);
}

int			check_nbr_ants(char *line, t_farm **farm)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (i == 0 && line[i] == '+')
			i++;
		if (!ft_isdigit(line[i]))
			ft_exit(farm);
		i++;
	}
	return (arrtoint(line, farm));
}
