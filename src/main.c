/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** CPE_matchstick_2017 made by Sanchez Lucas
*/

#include "my.h"

void print_link(link_t *link)
{
	my_printf("link->data = '%d'\n", link->data);
}

link_t *create_link(int data)
{
	link_t *link = malloc(sizeof(link_t));

	if (!link)
		return (NULL);
	link->data = data;
	link->next_list = NULL;
	return (link);
}

next_list_t *create_next(link_t *data)
{
	next_list_t *link = malloc(sizeof(next_list_t));

	if (!link)
		return (NULL);
	link->data = data;
	link->next = NULL;
	return (link);
}

void connect_link(link_t *link1, link_t *link2)
{
	next_list_t *tmp = link1->next_list;

	if (tmp == NULL) {
		link1->next_list = create_next(link2);
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_next(link2);
}

link_t *build_my_graph(void)
{
	link_t *first = create_link(42);
	link_t *link_60012 = create_link(60012);
	link_t *link_48 = create_link(48);
	link_t *link_30012 = create_link(30012);
	link_t *link_50012 = create_link(50012);
	link_t *link_3 = create_link(3);
	link_t *link_8 = create_link(8);
	link_t *link_98 = create_link(98);

	connect_link(first, link_60012);
	connect_link(first, link_48);
	connect_link(link_60012, link_30012);
	connect_link(link_48, link_50012);
	connect_link(link_50012, link_3);
	connect_link(link_3, link_98);
	connect_link(link_3, link_8);
	return (first);
}

void print_my_graph_data(link_t *graph)
{
	print_link(graph);
	while (graph->next_list) {	
		print_my_graph_data(graph->next_list->data);
		graph->next_list = graph->next_list->next;
	}
}

int main(void)
{
	link_t *graph = build_my_graph();

	print_my_graph_data(graph);
	return (0);
}
