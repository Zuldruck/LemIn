/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** get_rooms
*/

#include "lemin.h"

int fill_elem(room_list_t *room, char *buffer, bool start, bool end)
{
	char **word_tab = my_str_to_word_array(buffer, ' ');

	if (my_lemin_tablen(word_tab) != 3
	|| my_str_contain_char(word_tab[0], '-')
	|| !my_str_isnum(word_tab[1]) || !my_str_isnum(word_tab[2])) {
		my_free_tab(word_tab);
		return (84);
	}
	room->start = start;
	room->end = end;
	room->name = my_strdup(word_tab[0]);
	room->pos = (pos_t){my_getnbr(word_tab[1]), my_getnbr(word_tab[2])};
	room->next = NULL;
	my_free_tab(word_tab);
	return (0);
}

int fill_room_list(room_list_t *rooms, char *buffer, bool start, bool end)
{
	room_list_t *new_room;

	if (!rooms->name) {
		if (fill_elem(rooms, buffer, start, end) == 84)
			return (84);
		return (0);
	}
	new_room = malloc(sizeof(*new_room));
	if (fill_elem(new_room, buffer, start, end) == 84)
		return (84);
	while (rooms->next)
		rooms = rooms->next;
	rooms->next = new_room;
	return (0);
}

int check_command(char **buffer, room_list_t *rooms)
{
	if (!my_strcmp(*buffer, "##start")) {
		free(*buffer);		
		*buffer = get_next_line(0);				
		if (fill_room_list(rooms, *buffer, 1, 0) == 84)
			return (84);
		else
			return (1);
	} else if (!my_strcmp(*buffer, "##end")) {
		free(*buffer);
		*buffer = get_next_line(0);
		if (fill_room_list(rooms, *buffer, 0, 1) == 84)
			return (84);
		else
			return (1);
	}
	return (0);
}

int str_is_comment(char *str)
{
	if ((!my_strncmp(str, "#", 1) && my_strncmp(str, "##", 2))
	|| (!my_strncmp(str, "##", 2) && my_strcmp(str, "##start")
	&& my_strcmp(str, "##end"))) {
		free(str);
		return (1);
	}
	return (0);
}

room_list_t *get_rooms(void)
{
	room_list_t *rooms = malloc(sizeof(*rooms));
	char *buffer = get_next_line(0);

	rooms->name = NULL;
	for (int a = 0; str_contain_space(buffer); buffer = get_next_line(0)) {
		if (str_is_comment(buffer))
			continue;
		a = check_command(&buffer, rooms);
		if (a == 84
		|| (a == 0 && fill_room_list(rooms, buffer, 0, 0) == 84)) {
			free(buffer);
			return (NULL);
		}
		free(buffer);
	}
	get_links(buffer, 1);
	return (rooms);
}