#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_S
{
	NODE_S *next;
	int data;
} node_single;

node_single *create_singly_linked_list(int d);
void print_singly_linked_list(node_single *head);
void insert_singly_linked_list(node_single *head, int data, int index);
void delete_singly_linked_list(node_single **head, int index);

node_single *create_singly_linked_list(int d)
{
	node_single *head = (node_single *)malloc(sizeof(node_single));

	head->data = d;
	head->next = NULL;

	return head;
}

void print_singly_linked_list(node_single *head)
{
	node_single *curr = head;

	while (curr != NULL)
	{
		printf("%d->", curr->data);
		curr = curr->next;
	}

	puts("NULL");
}

void insert_singly_linked_list(node_single *head, int data, int index)
{
	int i = 0;
	node_single *curr = head;

	while (i != index - 1)
	{
		curr = curr->next;
		i++;
	}

	node_single *n = (node_single *)malloc(sizeof(node_single));
	n->next = curr->next;
	n->data = data;

	curr->next = n;
}

void delete_singly_linked_list(node_single **head, int index)
{
	node_single *curr = *head;
	int i = 0;

	if (index == 0)
	{
		*head = (*head)->next;
		return;
	}

	while (i != index - 1)
	{
		curr = curr->next;
		i++;
	}

	node_single *toDelete = curr->next;
	curr->next = curr->next->next;

	free(toDelete);
}