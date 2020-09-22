#include <stdio.h>
#include <stdlib.h>

#include "single_ll.h"

node_single *get_node(node_single *head, int n) {
	node_single *curr = head;

	for (int i = 0; i < n - 1; i++) {
		curr = curr->next;
	}

	node_single *last = head;

	while (curr->next != NULL) {
		curr = curr->next;
		last = last->next;
	}

	return last;
}

int main() {
	node_single *a = create_singly_linked_list(0);

	for (int i = 1; i < 10; i++)
		insert_singly_linked_list(a, i, i);

	print_singly_linked_list(a);
	node_single *b = get_node(a, 6);

	printf("%d\n", b->data);

	return 0;
}