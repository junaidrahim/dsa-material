// Last Midsem Question

#include "single_ll.h"
#include <math.h>

void subtract(node_single *a, node_single *b) {
	int a_n = 0;
	int b_n = 0;

	int power = 0;

	node_single *a_curr;
	node_single *b_curr;

	for (a_curr = a; a_curr != NULL; a_curr = a_curr->next) {
		a_n += a_curr->data * pow(10, power);
		power++;
	}

	power = 0;

	for (b_curr = b; b_curr != NULL; b_curr = b_curr->next) {
		b_n += b_curr->data * pow(10, power);
		power++;
	}
}