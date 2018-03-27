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