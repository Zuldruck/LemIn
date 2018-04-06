/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** CPE_matchstick_2017 made by Sanchez Lucas
*/

#include "my.h"

void free_links(link_t *links)
{
	link_t *tmp;

	while (links) {
		tmp = links;
		links = links->next;
		free(tmp->link_1);
		free(tmp->link_2);
		free(tmp);
	}
}

void free_lemin(lemin_t *lemin)
{
	next_list_t *tmp;

	while (lemin->rooms) {
		tmp = lemin->rooms;
		lemin->rooms = lemin->rooms->next;
		if (tmp->data && tmp->data->next_list)
			free(tmp->data->next_list);
		free(tmp->data->name);
		free(tmp->data);
		free(tmp);
	}
	free_links(lemin->links);
	free(lemin);
}

int main(int ac, char **av)
{
	lemin_t *lemin;

	(void)av;
	if (ac != 1)
		return (84);
	lemin = get_file_data();
	if (lemin == NULL
	|| connect_all_rooms(lemin->rooms, lemin->links) == 84
	|| get_start_end_rooms(lemin) == 84
	|| !check_link_start_end_rooms(lemin->start))
		return (84);
	reset_visited(lemin->start);
	print_lemin_data(lemin);
	print_fourmiz_path(lemin);
	free_lemin(lemin);
	return (0);
}
