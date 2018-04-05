/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** get_start_end_rooms
*/

#include "lemin.h"

room_t *get_start_room(next_list_t *rooms)
{
	while (rooms && !rooms->data->start)
		rooms = rooms->next;
	if (rooms == NULL)
		return (NULL);
	return (rooms->data);
}

room_t *get_end_room(next_list_t *rooms)
{
	while (rooms && !rooms->data->end)
		rooms = rooms->next;
	if (rooms == NULL)
		return (NULL);
	return (rooms->data);
}

int get_start_end_rooms(lemin_t *lemin)
{
	int start = 0;
	int end = 0;
	next_list_t *tmp = lemin->rooms;

	lemin->start = get_start_room(lemin->rooms);
	lemin->end = get_end_room(lemin->rooms);
	if (!lemin->start || !lemin->end)
		return (84);
	while (tmp) {
		if (tmp->data->end)
			end++;
		else if (tmp->data->start)
			start++;
		tmp = tmp->next;
	}
	if (start != 1 || end != 1)
		return (84);
	return (0);
}

int check_link_start_end_rooms(room_t *rooms)
{
	static int end = 0;
	next_list_t *tmp = rooms->next_list;

	if (rooms->end)
		end = 1;
	if (rooms->visited)
		return (0);
	rooms->visited = true;
	while (tmp) {
		check_link_start_end_rooms(tmp->data);
		tmp = tmp->next;
	}
	return (end);
}