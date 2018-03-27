/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** read_file
*/

#include "lemin.h"

lemin_t *get_file_data(void)
{
	int ants_nbr = get_ants_nbr();
	room_list_t *rooms = get_rooms();
	link_t *links = get_links(NULL, 0);
	lemin_t *lemin;

	if (ants_nbr <= 0 || rooms == NULL)
		return (NULL);
	lemin = malloc(sizeof(*lemin));
	lemin->ants_nbr = ants_nbr;
	lemin->rooms = rooms;
	lemin->links = links;
	return (lemin);
}