#include <stdio.h>
#include <stdlib.h>

#include "single_ll.h"

void delete_duplicates(node_single *head) {
	node_single *curr = head;
	node_single *currNext = head->next;

	while(currNext != NULL){
		if(curr->data == currNext->data){
			curr->next = curr->next->next;
		}
		
		curr = curr->next;
		currNext = currNext->next;
	}
}

int main() {
	node_single *a = create_singly_linked_list(0);

	insert_singly_linked_list(a, 1, 1);
	insert_singly_linked_list(a, 1, 2);
	insert_singly_linked_list(a, 2, 3);
	insert_singly_linked_list(a, 2, 4);
	insert_singly_linked_list(a, 3, 5);
	insert_singly_linked_list(a, 4, 6);
	
	print_singly_linked_list(a);
	delete_duplicates(a);
	print_singly_linked_list(a);

	return 0;
}