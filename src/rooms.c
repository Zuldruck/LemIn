/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** rooms
*/

#include "lemin.h"

next_list_t *create_next(room_t *data)
{
	next_list_t *room = malloc(sizeof(next_list_t));

	if (!room)
		return (NULL);
	room->data = data;
	room->next = NULL;
	return (room);
}

void connect_rooms(room_t *room1, room_t *room2)
{
	next_list_t *tmp = room1->next_list;

	if (!tmp) {
		room1->next_list = create_next(room2);
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_next(room2);
}

room_t *get_room(next_list_t *rooms, char *name)
{
	if (!name)
		return (NULL);
	while (rooms && rooms->data && my_strcmp(rooms->data->name, name))
		rooms = rooms->next;
	if (rooms == NULL)
		return (NULL);
	return (rooms->data);
}

room_t *get_room_with_coor(next_list_t *rooms, pos_t pos)
{
	while (rooms && rooms->data && rooms->data->pos.x != pos.x
	&& rooms->data->pos.y != pos.y)
		rooms = rooms->next;
	if (rooms == NULL)
		return (NULL);
	return (rooms->data);
}