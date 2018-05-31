/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** my_str_contain_space
*/

#include "lemin.h"

int str_contain_space(char *str)
{
	if (str == NULL)
		return (0);
	if (str[0] == '#')
		return (1);
	for (int i = 0; str[i]; i++) {
		if (str[i] == ' ')
			return (1);
	}
	return (0);
}

int my_str_contain_char(char *str, char c)
{
	if (str == NULL)
		return (0);
	for (int i = 0; str[i]; i++) {
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int lemin_tab_error(char **word_tab)
{
	if (my_lemin_tablen(word_tab) != 3
	|| my_str_contain_char(word_tab[0], '-')
	|| !my_str_isnum(word_tab[1]) || !my_str_isnum(word_tab[2])) {
		my_free_tab(word_tab);
		return (84);
	}
	return (0);
}

int check_start_end(bool start, bool end)
{
	static bool start_pass = 0;
	static bool end_pass = 0;

	if (start && start_pass)
		return (1);
	else if (end && end_pass)
		return (1);
	if (start)
		start_pass = 1;
	else if (end)
		end_pass = 1;
	return (0);
}