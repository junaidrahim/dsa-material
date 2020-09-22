#include <stdio.h>
#include <stdlib.h>

#include "double_ll.h"

void swap(node_double **a, node_double **b) {
	node_double *t = *a;
	*a = *b;
	*b = t;
}

node_double *reverse(node_double *head) {
	node_double *last = head;

	while (last->next != NULL)
		last = last->next;

	node_double *curr = last;

	while (curr != NULL) {
		swap(&(curr->next), &(curr->prev));
		curr = curr->next;
	}

	return last;
}

int main() {
	node_double *a = create_doubly_linked_list(0);

	for (int i = 1; i < 10; i++)
		insert_doubly_linked_list(a, i, i);

	print_doubly_linked_list(a);

	node_double *l = reverse(a);

	print_doubly_linked_list(l);

	return 0;
}