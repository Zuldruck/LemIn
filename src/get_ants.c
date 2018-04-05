/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** get_ants
*/

#include "lemin.h"

int get_ants_nbr(void)
{
	char *str = get_next_line(0);
	int nbr = 0;

	if (str == NULL)
		return (-1);
	while (str && str[0] == '#') {
		free(str);
		str = get_next_line(0);
	}
	if (my_str_isnum(str) == 0 || !str)
		return (-1);
	nbr = my_getnbr(str);
	if (nbr <= 0)
		return (-1);
	return (nbr);
}