#include <stdio.h>
#include <stdlib.h>

#include "single_ll.h"

void arrange_odd_even (node_single **head) {
	node_single *last = *head;
	
	while(last->next != NULL)
		last = last->next;

	if((*head)->data%2 == 0){	
		last->next = *head;
		(*head) = (*head)->next;
		last = last->next;
		last->next = NULL;
	}

	node_single *curr = *head;
	
	while(curr->next != NULL){
		if(curr->next->data % 2 == 0){
			// move the node to the end
			last->next = curr->next;
			curr->next = curr->next->next;
			last = last->next;
			last->next = NULL;
		}

		curr = curr->next;
	}
}

int main(){
	node_single *a = create_singly_linked_list(0);

	for(int i=1; i<10; i++)
		insert_singly_linked_list(a, i, i);

	print_singly_linked_list(a);
	arrange_odd_even(&a);
	print_singly_linked_list(a);

	return 0;
}