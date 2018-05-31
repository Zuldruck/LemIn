/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** print_data
*/

#include "lemin.h"

void print_room(room_t *room)
{
	static int pass = 0;

	if (pass == 0) {
		my_printf("#rooms\n");
		pass = 1;
	}
	if (room->start)
		my_printf("##start\n");
	else if (room->end)
		my_printf("##end\n");
	my_printf("%s %d %d\n", room->name, room->pos.x, room->pos.y);
}

void print_link(link_t *link)
{
	static int pass = 0;

	if (pass == 0) {
		my_printf("#tunnels\n");
		pass = 1;
	}
	my_printf("%s-%s\n", link->link_1, link->link_2);
}