/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** rooms
*/

#include "lemin.h"

void print_room(room_t *room)
{
	my_printf("room->data = '%d'\n", room->name);
}

room_t *create_room(char *name)
{
	room_t *room = malloc(sizeof(room_t));

	if (!room)
		return (NULL);
	room->name = name;
	room->next_list = NULL;
	return (room);
}

next_list_t *create_next(room_t *data)
{
	next_list_t *room = malloc(sizeof(next_list_t));

	if (!room)
		return (NULL);
	room->data = data;
	room->next = NULL;
	return (room);
}

void connect_room(room_t *room1, room_t *room2)
{
	next_list_t *tmp = room1->next_list;

	if (tmp == NULL) {
		room1->next_list = create_next(room2);
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_next(room2);
}

void print_my_graph_data(room_t *graph)
{
	print_room(graph);
	while (graph->next_list) {	
		print_my_graph_data(graph->next_list->data);
		graph->next_list = graph->next_list->next;
	}
}