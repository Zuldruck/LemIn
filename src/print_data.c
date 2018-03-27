/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** print_data
*/

#include "lemin.h"

void print_lemin_rooms(room_list_t *rooms)
{
	my_printf("#rooms\n");
	while (rooms) {
		if (rooms->start)
			my_printf("##start\n");
		else if (rooms->end)
			my_printf("##end\n");
		my_printf("%s %d %d\n", rooms->name, rooms->pos.x,
							rooms->pos.y);
		rooms = rooms->next;
	}
}

void print_lemin_links(link_t *links)
{
	my_printf("#tunnels\n");
	while (links) {
		my_printf("%s-%s\n", links->link_1, links->link_2);
		links = links->next;
	}
}

void print_lemin_data(lemin_t *lemin)
{
	my_printf("#number_of_ants\n%d\n", lemin->ants_nbr);
	print_lemin_rooms(lemin->rooms);
	print_lemin_links(lemin->links);
}