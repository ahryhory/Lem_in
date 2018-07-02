/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:55:38 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/06 12:55:39 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		not_link(char *line)
{
	char	**split;
	int		count;

	if (line)
	{
		if (line[0] == '#')
			return (1);
	}
	split = ft_strsplit(line, ' ');
	if (split == NULL)
		return (0);
	count = 0;
	while (split[count])
		count++;
	ft_clr(&split);
	if (count != 3)
		return (0);
	return (1);
}
