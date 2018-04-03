/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** connect_rooms
*/

#include "lemin.h"

int connect_all_rooms(next_list_t *rooms, link_t *links)
{
	room_t *room_1 = NULL;
	room_t *room_2 = NULL;

	while (links) {
		room_1 = get_room(rooms, links->link_1);
		room_2 = get_room(rooms, links->link_2);
		if (!room_1 || !room_2)
			return (84);
		connect_rooms(room_1, room_2);
		connect_rooms(room_2, room_1);
		links = links->next;
	}
	return (0);
}