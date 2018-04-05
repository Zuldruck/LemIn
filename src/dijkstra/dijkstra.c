/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** find_shortest_path
*/

#include "lemin.h"

void dijkstra_set_rooms(room_t *rooms, room_t *prev)
{
	next_list_t *tmp = rooms->next_list;

	if (rooms->visited && prev && 1 + prev->distance > rooms->distance)
		return;
	if (rooms->distance >= 0
	&& prev && 1 + prev->distance > rooms->distance)
		return;
	rooms->visitor = prev;
	rooms->distance = (prev ? 1 + prev->distance : 0);
	if (rooms->end)
		return;
	rooms->visited = true;
	while (tmp) {
		dijkstra_set_rooms(tmp->data, rooms);
		tmp = tmp->next;
	}
}

void add_elem_to_path(path_t *path, char *name, int nb_ants)
{
	path_t *new_elem = malloc(sizeof(*new_elem));

	while (path->next)
		path = path->next;
	new_elem->name = my_strdup(name);
	new_elem->nb_ants = nb_ants;
	new_elem->prev = path;
	new_elem->next = NULL;
	new_elem->ants_visited = 0;
	path->next = new_elem;
}

path_t *get_shortest_path(lemin_t *lemin)
{
	path_t *path = NULL;
	char **names = NULL;
	int path_length = 0;

	dijkstra_set_rooms(lemin->start, NULL);
	path = malloc(sizeof(*path));
	names = malloc(sizeof(*names) * (lemin->end->distance + 1));
	path_length = lemin->end->distance;
	path->name = my_strdup(lemin->start->name);
	path->nb_ants = lemin->ants_nbr;
	path->ants_visited = lemin->ants_nbr;
	path->prev = NULL;
	path->next = NULL;
	for (int i = 0; lemin->end->visitor; lemin->end = lemin->end->visitor)
		names[path_length - 1 - i++] = my_strdup(lemin->end->name);
	names[path_length] = NULL;
	for (int i = 0; names[i]; i++)
		add_elem_to_path(path, names[i], 0);
	my_free_tab(names);
	return (path);
}