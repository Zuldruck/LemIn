/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** get_links
*/

#include "lemin.h"

void set_first_link(char **first_link, char *str)
{
	if (str == NULL) {
		*first_link = NULL;
		return;
	}
	*first_link = my_strdup(str);
	free(str);
}

void set_link(next_list_t *rooms, link_t *link, char **tab)
{
	(void)rooms;
	link->link_1 = my_strdup(tab[0]);
	link->link_2 = my_strdup(tab[1]);
	print_link(link);
	link->next = NULL;
	my_free_tab(tab);
}

int fill_link(next_list_t *rooms, link_t *link, char *str)
{
	char **tab = my_str_to_word_array(str, '-');
	link_t *new_link;

	free(str);
	if (my_tablen(tab) != 2 || !get_room(rooms, tab[0])
	|| !get_room(rooms, tab[1])) {
		my_free_tab(tab);
		return (84);
	}
	if (!link->link_1) {
		set_link(rooms, link, tab);
		return (0);
	}
	new_link = malloc(sizeof(*new_link));
	while (link->next)
		link = link->next;
	set_link(rooms, new_link, tab);
	link->next = new_link;
	return (0);
}

link_t *get_links(next_list_t *rooms, char *first_link, bool first_entry)
{
	static char *first;
	link_t *links;

	if (first_entry) {
		set_first_link(&first, first_link);
		return (NULL);
	}
	links = malloc(sizeof(*links));
	links->link_1 = NULL;
	if (fill_link(rooms, links, first) == 84)
		return (NULL);
	for (first = get_next_line(0); first; first = get_next_line(0)) {
		if (str_is_comment(first))
			continue;
		if (fill_link(rooms, links, first) == 84)
			return (NULL);
	}
	return (links);
}