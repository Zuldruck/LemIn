/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** NULL
*/

#ifndef LEMIN
#define LEMIN

typedef struct next_list_s {
	struct link_s *data;
	struct next_list_s *next;
} next_list_t;

typedef struct link_s {
	int data;
	struct next_list_s *next_list;
} link_t;

#endif /* LEMIN */
