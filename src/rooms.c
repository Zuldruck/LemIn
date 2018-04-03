/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** rooms
*/

#include "lemin.h"

void print_room(room_t *room)
{
	my_printf("%s\n", room->name);
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

void print_my_graph_data(room_t *graph)
{
	print_room(graph);
	if (graph->visited)
		return;
	graph->visited = true;
	while (graph->next_list) {
		my_printf("%s ->", graph->name);	
		print_my_graph_data(graph->next_list->data);
		graph->next_list = graph->next_list->next;
	}
}

room_t *get_room(next_list_t *rooms, char *name)
{
	while (rooms && my_strcmp(rooms->data->name, name))
		rooms = rooms->next;
	if (rooms == NULL)
		return (NULL);
	return (rooms->data);
}