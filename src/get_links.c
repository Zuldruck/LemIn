/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** get_links
*/

#include "lemin.h"

void set_first_link(char **first_link, char *str)
{
	*first_link = my_strdup(str);
	free(str);
}

void set_link(link_t *link, char *link1, char *link2)
{
	link->link_1 = my_strdup(link1);
	link->link_2 = my_strdup(link2);
	link->next = NULL;
}

int fill_link(link_t *link, char *str)
{
	char **tab = my_str_to_word_array(str, '-');
	link_t *new_link;

	free(str);
	if (my_tablen(tab) != 2) {
		my_free_tab(tab);
		return (84);
	}
	if (!link->link_1) {
		set_link(link, tab[0], tab[1]);
		my_free_tab(tab);
		return (0);
	}
	new_link = malloc(sizeof(*new_link));
	while (link->next)
		link = link->next;
	set_link(new_link, tab[0], tab[1]);
	link->next = new_link;
	my_free_tab(tab);
	return (0);
}

link_t *get_links(char *first_link, bool first_entry)
{
	static char *first;
	link_t *links;

	if (first_entry) {
		set_first_link(&first, first_link);
		return (NULL);
	}
	links = malloc(sizeof(*links));
	links->link_1 = NULL;
	if (fill_link(links, first) == 84)
		return (NULL);
	for (first = get_next_line(0); first; first = get_next_line(0)) {
		if (str_is_comment(first))
			continue;
		if (fill_link(links, first) == 84)
			return (NULL);
	}
	return (links);
}