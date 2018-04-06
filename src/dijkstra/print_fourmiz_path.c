/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** print_fourmiz_path
*/

#include "lemin.h"

int another_fourmiz_to_move(path_t *path)
{
	while (path) {
		path = path->prev;
	}
	return (0);
}

void move_fourmiz(path_t *path, int *ants)
{
	int ants_moved = 0;

	while (path->next->next)
		path = path->next;
	while (path) {
		if (path->nb_ants && ants_moved > 0)
			my_putchar(' ');
		if (path->nb_ants) {
			my_printf("P%d-%s", path->next->ants_visited + 1,
							path->next->name);
			ants_moved += 1;
			path->nb_ants -= 1;
			path->next->nb_ants += 1;
			path->next->ants_visited += 1;
			*ants -= !path->next->next ? 1 : 0;
		}
		path = path->prev;
	}
	my_putchar('\n');
}

void free_path(path_t *path)
{
	path_t *tmp;

	while (path) {
		tmp = path;
		path = path->next;
		free(tmp->name);
		free(tmp);
	}
}

void print_fourmiz_path(lemin_t *lemin)
{
	path_t *path = get_shortest_path(lemin);
	int ants_nbr = lemin->ants_nbr;

	my_printf("#moves\n");
	while (ants_nbr)
		move_fourmiz(path, &ants_nbr);
	free_path(path);
}