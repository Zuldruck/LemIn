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
typedef struct dijkstra_s dijkstra_t;
typedef struct dijkstra_rooms_s dijkstra_rooms_t;
typedef struct path_s path_t;

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
	int distance;
	bool start;
	bool end;
	int nb_ants;
	bool visited;
	pos_t pos;
	room_t *visitor;
	next_list_t *next_list;
} room_t;

typedef struct lemin_s {
	int ants_nbr;
	room_t *start;
	room_t *end;
	next_list_t *rooms;
	link_t *links;
} lemin_t;

typedef struct path_s {
	char *name;
	int nb_ants;
	int ants_visited;
	path_t *prev;
	path_t *next;
} path_t;

void print_room(room_t *);
room_t *create_room(char *);
next_list_t *create_next(room_t *);
void connect_rooms(room_t *, room_t *);
void print_my_graph_data(room_t *);
lemin_t *get_file_data(void);
int get_ants_nbr(void);
next_list_t *get_rooms(void);
link_t *get_links(char *, bool);
int my_lemin_tablen(char **);
void print_lemin_data(lemin_t *);
int str_contain_space(char *);
int my_str_contain_char(char *, char);
int str_is_comment(char *);
int get_start_end_rooms(lemin_t *);
int connect_all_rooms(next_list_t *, link_t *);
room_t *get_room(next_list_t *, char *);
void reset_visited(room_t *);
int check_link_start_end_rooms(room_t *);
path_t *get_shortest_path(lemin_t *);
int lemin_tab_error(char **);
void print_fourmiz_path(lemin_t *);

#endif /* LEMIN */
