#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_S2 {
	struct NODE_S2 *next;
	struct NODE_S2 *prev;
	int data;
} node_double;

node_double *create_doubly_linked_list(int d);
void print_doubly_linked_list(node_double *head);
void insert_doubly_linked_list(node_double *head, int data, int index);
void delete_doubly_linked_list(node_double **head, int index);

node_double *create_doubly_linked_list(int d) {
	node_double *head = (node_double *)malloc(sizeof(node_double));

	head->data = d;
	head->prev = NULL;
	head->next = NULL;

	return head;
}

void print_doubly_linked_list(node_double *head) {
	node_double *curr = head;

	while (curr != NULL) {
		printf("%d->", curr->data);
		curr = curr->next;
	}

	puts("NULL");
}

void insert_doubly_linked_list(node_double *head, int data, int index) {
	int i = 0;
	node_double *curr = head;

	while (i != index - 1) {
		curr = curr->next;
		i++;
	}

	node_double *n = (node_double *)malloc(sizeof(node_double));
	n->data = data;
	n->next = curr->next;
	n->prev = curr;

	curr->next = n;

	if (n->next) n->next->prev = n;
}

void delete_doubly_linked_list(node_double **head, int index) {
	node_double *curr = *head;
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

	node_double *toDelete = curr->next;

	if (curr->next->next) {
		curr->next = curr->next->next;
		curr->next->prev = curr;
	} else {
		curr->next = NULL;
	}

	free(toDelete);
}
