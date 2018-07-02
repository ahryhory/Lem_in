/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:59:44 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/02 14:59:46 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_to_data(t_data **data, char *line)
{
	t_data	*tmp;

	if (*data == NULL)
	{
		*data = (t_data *)malloc(sizeof(t_data));
		(*data)->line = line;
		(*data)->next = NULL;
	}
	else
	{
		tmp = *data;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (t_data *)malloc(sizeof(t_data));
		tmp->next->line = line;
		tmp->next->next = NULL;
	}
}
