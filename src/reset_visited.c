/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** set_visited_to_zero
*/

#include "lemin.h"

void reset_visited(room_t *graph)
{
	next_list_t *tmp = graph->next_list;

	if (!graph->visited)
		return;
	graph->visited = false;
	while (tmp) {
		reset_visited(tmp->data);
		tmp = tmp->next;
	}
}