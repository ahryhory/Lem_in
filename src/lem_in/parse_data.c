/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:05:56 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/02 16:05:57 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	parse_hash(t_farm **p_farm, t_data **p_data)
{
	t_farm	*farm;
	t_data	*data;

	farm = *p_farm;
	data = *p_data;
	if (ft_strequ(data->line, START))
	{
		if (data->next == NULL || farm->start != NULL)
			ft_exit(p_farm);
		farm->start = check_rooms(data->next->line, p_farm);
	}
	else if (ft_strequ(data->line, END))
	{
		if (data->next == NULL || farm->end != NULL)
			ft_exit(p_farm);
		farm->end = check_rooms(data->next->line, p_farm);
	}
}

static void	parse_rooms(t_farm **p_farm, t_data **p_data, int index)
{
	t_data	*data;

	data = *p_data;
	index = 1;
	while (data)
	{
		if (not_link(data->line))
		{
			if (ft_strequ(data->line, ""))
				ft_exit(p_farm);
			if (data->line[0] == '#')
				parse_hash(p_farm, &data);
			else
			{
				add_to_rooms(&((*p_farm)->rooms),
					check_rooms(data->line, p_farm),
					check_coords(data->line, p_farm), index);
				index++;
			}
		}
		else
			break ;
		data = data->next;
	}
	*p_data = data;
}

static int	chek_comment(char *comment)
{
	if (ft_strequ(comment, START) || ft_strequ(comment, END))
		return (0);
	else
		return (1);
}

static void	parse_links(t_farm **p_farm, t_data **p_data)
{
	t_farm	*farm;
	t_data	*data;

	farm = *p_farm;
	data = *p_data;
	while (data)
	{
		if (ft_strequ(data->line, ""))
			break ;
		else if (data->line[0] == '#')
		{
			if (!chek_comment(data->line))
				break ;
		}
		else if (add_to_links(&((*p_farm)->links), *p_farm,
			check_links(data->line, p_farm)) < 0)
			break ;
		data = data->next;
	}
	if (data)
		ft_exit(p_farm);
	*p_data = data;
}

void		parse_data(t_farm **p_farm)
{
	t_farm	*farm;
	t_data	*data;
	int		index;

	index = 0;
	farm = *p_farm;
	data = farm->data;
	if (data)
	{
		if (ft_strequ(data->line, ""))
			ft_exit(p_farm);
		farm->ants = check_nbr_ants(data->line, p_farm);
		data = data->next;
	}
	parse_rooms(p_farm, &data, index);
	if ((*p_farm)->start == NULL || (*p_farm)->end == NULL)
		ft_exit(p_farm);
	parse_links(p_farm, &data);
	if ((*p_farm)->links == NULL)
		ft_exit(p_farm);
}
