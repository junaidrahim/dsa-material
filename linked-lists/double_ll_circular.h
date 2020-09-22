#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_C_S2 {
	struct NODE_C_S2 *next;
	struct NODE_C_S2 *prev;
	int data;
} node_double_c;

node_double_c *create_double_circular_linked_list(int d);
void print_double_circular_linked_list(node_double_c *head);
void insert_double_circular_linked_list(node_double_c *head, int data, int index);
void delete_double_circular_linked_list(node_double_c **head, int index);

node_double_c *create_double_circular_linked_list(int d) {
	node_double_c *head = (node_double_c *)malloc(sizeof(node_double_c));

	head->data = d;
	head->prev = head;
	head->next = head;

	return head;
}

void print_double_circular_linked_list(node_double_c *head) {
	node_double_c *curr = head;

	while (curr->next != head) {
		printf("%d->", curr->data);
		curr = curr->next;
	}

	printf("%d\n", curr->data);
}

void insert_double_circular_linked_list(node_double_c *head, int data, int index) {
	int i = 0;
	node_double_c *curr = head;

	while (i != index - 1) {
		curr = curr->next;
		i++;
	}

	node_double_c *n = (node_double_c *)malloc(sizeof(node_double_c));
	n->data = data;
	n->next = curr->next;
	n->prev = curr;

	curr->next = n;

	if (n->next == head) n->next->prev = n;
}

void delete_double_circular_linked_list(node_double_c **head, int index) {
	node_double_c *curr = *head;
	int i = 0;

	if (index == 0) {
		*head = (*head)->next;
		(*head)->prev = NULL;
		return;
	}

	while (i != index - 1) {
		curr = curr->next;
		i++;
	}

	node_double_c *toDelete = curr->next;

	if (curr->next->next) {
		curr->next = curr->next->next;
		curr->next->prev = curr;
	} else {
		curr->next = NULL;
	}

	free(toDelete);
}
