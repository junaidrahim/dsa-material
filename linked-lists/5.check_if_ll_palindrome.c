#include <stdio.h>
#include <stdlib.h>

#include "single_ll.h"

void is_palindrome(node_single *head) {
	int len = 0;

	node_single *curr = head;
	
	while(curr != NULL){
		len++;
		curr = curr->next;
	}

	int stack[len];
	curr = head;
	stack[0] = curr->data;
	curr = curr->next;

	int index = 0;

	while(curr != NULL){
		if(curr->data != stack[index]){
			stack[++index] = curr->data;
		} else {
			stack[index] = -1;
			index--;
		}

		curr = curr->next;
	}

	if(index == 0)
		puts("Palindrome");
	else 
		puts("Not Palindrome");
}


int main(){
	node_single *a = create_singly_linked_list(0);

	insert_singly_linked_list(a, 1, 1);
	insert_singly_linked_list(a, 1, 2);
	insert_singly_linked_list(a, 2, 3);
	insert_singly_linked_list(a, 2, 4);
	insert_singly_linked_list(a, 1, 5);
	insert_singly_linked_list(a, 1, 6);
	
	print_singly_linked_list(a);
	is_palindrome(a);

	return 0;
}