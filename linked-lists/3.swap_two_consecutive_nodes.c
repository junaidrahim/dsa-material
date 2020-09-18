#include <stdio.h>

#include "single_ll.h"

node_single* swap_consecutive(node_single* head) {
	if (head == NULL || head->next == NULL) 
        return head; 

    node_single* remaing = head->next->next; 
    node_single* newhead = head->next; 
 
    head->next->next = head; 
    head->next = swap_consecutive(remaing); 
  
    return newhead; 
}

int main(){
	node_single *a = create_singly_linked_list(0);
	
	for(int i=1;i<10;i++)
		insert_singly_linked_list(a,i,i);
	
	print_singly_linked_list(a);
	a = swap_consecutive(a);
	print_singly_linked_list(a);

	return 0;
}