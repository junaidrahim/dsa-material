// non recursive method to display linked list in reverse order

#include <stdio.h>
#include <stdlib.h>

#include "single_ll.h"

void print_reverse(node_single *head){
	for(int i=9; i >= 1; i--){
		node_single *curr = head;
		for(int j=0; j<i; j++){
			curr = curr->next;
		}

		printf("%d ", curr->data);
	}
}

int main(){
	node_single* a = create_singly_linked_list(0);
	
	for(int i=1; i<10; i++)
		insert_singly_linked_list(a, i, i);
	
	print_singly_linked_list(a);
	print_reverse(a);

	return 0;
}