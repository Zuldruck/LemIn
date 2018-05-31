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

int verif_start_end(next_list_t *rooms)
{
	int start = 0;
	int end = 0;
	next_list_t *list = rooms;

	while (list) {
		if (list->data->start)
			start += 1;
		else if (list->data->end)
			end += 1;
		list = list->next;
	}
	if (start == 1 && end == 1)
		return (1);
	return (0);
}

lemin_t *get_file_data(void)
{
	int ants_nbr = 0;
	next_list_t *rooms = NULL;
	link_t *links = NULL;
	lemin_t *lemin;

	ants_nbr = get_ants_nbr();
	if (ants_nbr <= 0)
		return (NULL);
	rooms = get_rooms();
	if (!rooms || check_rooms(rooms) == 84 || !verif_start_end(rooms))
		return (NULL);
	links = get_links(rooms, NULL, 0);
	if (!links)
		return (NULL);
	lemin = malloc(sizeof(*lemin));
	lemin->ants_nbr = ants_nbr;
	lemin->rooms = rooms;
	lemin->links = links;
	return (lemin);
}