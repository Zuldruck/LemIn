/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** NULL
*/

#ifndef LEMIN
#define LEMIN

#include "my.h"
#include <stdbool.h>

typedef struct room_s room_t;
typedef struct next_list_s next_list_t;
typedef struct link_s link_t;
typedef struct room_list_s room_list_t;

typedef struct pos_s {	
	int x;
	int y;
} pos_t;

typedef struct link_s {
	char *link_1;
	char *link_2;
	link_t *next;
} link_t;

typedef struct next_list_s {
	room_t *data;
	next_list_t *next;
} next_list_t;

typedef struct room_s {
	char *name;
	bool start;
	bool end;
	bool full;
	pos_t pos;
	next_list_t *next_list;
} room_t;

typedef struct room_list_s {
	char *name;
	bool start;
	bool end;
	pos_t pos;
	room_list_t *next;
} room_list_t;

typedef struct lemin_s {
	int ants_nbr;
	room_t *start;
	room_t *end;
	room_list_t *rooms;
	link_t *links;
} lemin_t;

void print_room(room_t *);
room_t *create_room(char *);
next_list_t *create_next(room_t *);
void connect_rooms(room_t *, room_t *);
void print_my_graph_data(room_t *);
lemin_t *get_file_data(void);
int get_ants_nbr(void);
room_list_t *get_rooms(void);
link_t *get_links(char *, bool);
int my_lemin_tablen(char **);
void print_lemin_data(lemin_t *);
int str_contain_space(char *);
int my_str_contain_char(char *, char);
int str_is_comment(char *);

#endif /* LEMIN */
