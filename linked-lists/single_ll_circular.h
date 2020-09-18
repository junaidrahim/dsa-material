#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_C_S
{
	NODE_C_S *next;
	int data;
} node_single_c;

node_single_c *create_singly_circular_linked_list(int d);
void print_singly_circular_linked_list(node_single_c *head);
void insert_singly_circular_linked_list(node_single_c *head, int data, int index);
void delete_singly_circular_linked_list(node_single_c **head, int index);

node_single_c *create_singly_circular_linked_list(int d)
{
	node_single_c *head = (node_single_c *)malloc(sizeof(node_single_c));

	head->data = d;
	head->next = head;

	return head;
}

void print_singly_circular_linked_list(node_single_c *head)
{
	node_single_c *curr = head;

	while (curr->next != head)
	{
		printf("%d->", curr->data);
		curr = curr->next;
	}

	printf("%d\n", curr->data);
}

void insert_singly_circular_linked_list(node_single_c *head, int data, int index)
{
	int i = 0;
	node_single_c *curr = head;

	while (i != index - 1)
	{
		curr = curr->next;
		i++;
	}

	node_single_c *n = (node_single_c *)malloc(sizeof(node_single_c));
	n->next = curr->next;
	n->data = data;

	curr->next = n;

	if(n->next == NULL)
		n->next = head;
}

void delete_singly_circular_linked_list(node_single_c **head, int index)
{
	node_single_c *curr = *head;
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

	node_single_c *toDelete = curr->next;
	
	curr->next = curr->next->next;
	
	free(toDelete);
}