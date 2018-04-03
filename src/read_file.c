/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** read_file
*/

#include "lemin.h"

int check_each_rooms(next_list_t *rooms, char *name, pos_t pos)
{
	int nb_name = 0;
	int nb_pos = 0;

	while (rooms) {
		if (!my_strcmp(rooms->data->name, name))
			nb_name += 1;
		if (pos.x == rooms->data->pos.x && pos.y == rooms->data->pos.y)
			nb_pos += 1;
		rooms = rooms->next;
	}
	if (nb_name != 1 || nb_pos != 1)
		return (84);
	return (0);
}

int check_rooms(next_list_t *rooms)
{
	next_list_t *tmp = rooms;

	while (tmp) {
		if (check_each_rooms(rooms, tmp->data->name, \
		tmp->data->pos) == 84)
			return (84);
		tmp = tmp->next;
	}
	return (0);
}

lemin_t *get_file_data(void)
{
	int ants_nbr = get_ants_nbr();
	next_list_t *rooms = get_rooms();
	link_t *links = get_links(NULL, 0);
	lemin_t *lemin;

	if (ants_nbr <= 0 || !rooms || !links)
		return (NULL);
	if (check_rooms(rooms) == 84)
		return (NULL);
	lemin = malloc(sizeof(*lemin));
	lemin->ants_nbr = ants_nbr;
	lemin->rooms = rooms;
	lemin->links = links;
	return (lemin);
}