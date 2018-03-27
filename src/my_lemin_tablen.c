/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** my_lemin_tablen
*/

#include "lemin.h"

int my_lemin_tablen(char **tab)
{
	int i = 0;

	while (tab[i]) {
		if (!my_strncmp(tab[i], "#", 1))
			break;
		i++;
	}
	return (i);
}