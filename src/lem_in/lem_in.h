/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:24:02 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/01 11:33:37 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define START "##start"
# define END "##end"
# include "../libft/libft.h"

typedef struct		s_data
{
	char			*line;
	struct s_data	*next;
}					t_data;

typedef struct		s_rooms
{
	char			*name;
	int				coord_1;
	int				coord_2;
	int				index;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_links
{
	char			**link;
	int				index_1;
	int				index_2;
	struct s_links	*next;
}					t_links;

typedef struct		s_ants
{
	int				*way;
}					t_ants;

typedef struct		s_farm
{
	int				ants;
	int				first_move;
	char			*start;
	char			*end;
	t_data			*data;
	t_rooms			*rooms;
	t_links			*links;
}					t_farm;

void				ft_exit(t_farm **farm);
int					check_nbr_ants(char *line, t_farm **farm);
void				add_to_data(t_data **data, char *line);
void				add_to_rooms(t_rooms **rooms, char *name, int *coord,
									int index);
int					add_to_links(t_links **links, t_farm *farm, char **link);
void				free_all_farm(t_farm **farm);
void				print_data(t_data *data);
void				parse_data(t_farm **farm);
char				*check_rooms(char *room, t_farm **p_farm);
char				**check_links(char *str_links, t_farm **p_farm);
void				ft_clr(char ***str);
int					*find_way(t_farm **p_farm);
void				move_to_depth(t_farm *farm, int ***p_matr,
									int curent, int depth);
void				next_step(int ***p_matr, int start_end[2],
								int **way, int j);
void				print_way(int *way, t_farm *farm);
int					get_end_indx(t_farm *farm);
int					get_start_indx(t_farm *farm);
void				free_matr(int ***p_matr);
int					*check_coords(char *room, t_farm **p_farm);
int					not_link(char	*line);

#endif
