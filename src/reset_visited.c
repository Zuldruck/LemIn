/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** set_visited_to_zero
*/

#include "lemin.h"

void reset_visited(room_t *graph)
{
	if (!graph->visited)
		return;
	graph->visited = false;
	while (graph->next_list) {
		reset_visited(graph->next_list->data);
		graph->next_list = graph->next_list->next;
	}
}