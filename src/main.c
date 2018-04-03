/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** CPE_matchstick_2017 made by Sanchez Lucas
*/

#include "my.h"

// link_t *build_my_graph(void)
// {
// 	link_t *first = create_link(42);
// 	link_t *link_60012 = create_link(60012);
// 	link_t *link_48 = create_link(48);
// 	link_t *link_30012 = create_link(30012);
// 	link_t *link_50012 = create_link(50012);
// 	link_t *link_3 = create_link(3);
// 	link_t *link_8 = create_link(8);
// 	link_t *link_98 = create_link(98);

// 	connect_link(first, link_60012);
// 	connect_link(first, link_48);
// 	connect_link(link_60012, link_30012);
// 	connect_link(link_48, link_50012);
// 	connect_link(link_50012, link_3);
// 	connect_link(link_3, link_98);
// 	connect_link(link_3, link_8);
// 	return (first);
// }

void free_lemin(lemin_t *lemin)
{
	next_list_t *tmp;

	while (lemin->rooms) {
		tmp = lemin->rooms;
		lemin->rooms = lemin->rooms->next;
		free(tmp->data->name);
		free(tmp->data);
		free(tmp);
	}
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
	print_lemin_data(lemin);
	free_lemin(lemin);
	return (0);
}
