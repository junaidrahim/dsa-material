#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_S {
	struct NODE_S *next;
	int coeff;
	int power;
} node;

node *create_poly(int c, int p) {
	node *head = (node *)malloc(sizeof(node));

	head->coeff = c;
	head->power = p;
	head->next = NULL;

	return head;
}

void insert_poly(node *head, int index, int c, int p) {
	int i = 0;
	node *curr = head;

	while (i != index - 1) {
		curr = curr->next;
		i++;
	}

	node *n = (node *)malloc(sizeof(node));
	n->next = curr->next;
	n->coeff = c;
	n->power = p;

	curr->next = n;
}

void print(node *head) {
	node *curr = head;

	while (curr != NULL) {
		if (curr->coeff != 0) printf("%dx^%d ", curr->coeff, curr->power);

		curr = curr->next;
	}
	puts("");
}

node *add_ploy(node *a, node *b) {
	node *curr_a = a;
	node *curr_b = b;

	int index = 1;
	node *sum = create_poly(0, 0);

	while(curr_a->next && curr_b->next) {
		if(curr_a->power > curr_b->power) {
			insert_poly(sum, index, curr_a->coeff, curr_a->power);
			index++;
			curr_a = curr_a->next;
		} else if (curr_a->power < curr_b->power) {
			insert_poly(sum, index, curr_b->coeff, curr_b->power);
			index++;
			curr_b = curr_b->next;
		} else { // powers are equal
			insert_poly(sum, index, curr_a->coeff + curr_b->coeff, curr_a->power);
			index++;
			curr_a = curr_a->next;
			curr_b = curr_b->next;
		}
	}

	while (curr_a->next || curr_b->next) {
		if(curr_a->next){
			insert_poly(sum, index, curr_a->coeff, curr_a->power);
			index++;
			curr_a = curr_a->next;
		} 
		
		if (curr_b->next) {
			insert_poly(sum, index, curr_b->coeff, curr_b->power);
			index++;
			curr_b = curr_b->next;
		}		
	}

	return sum;
}

node *sub_ploy(node *a, node *b) {
	node *curr_a = a;
	node *curr_b = b;

	int index = 1;
	node *diff = create_poly(0, 0);


	while(curr_a->next && curr_b->next) {
		if(curr_a->power > curr_b->power) {
			insert_poly(diff, index, curr_a->coeff, curr_a->power);
			index++;
			curr_a = curr_a->next;
		} else if (curr_a->power < curr_b->power) {
			insert_poly(diff, index, curr_b->coeff, curr_b->power);
			index++;
			curr_b = curr_b->next;
		} else { // powers are equal
			insert_poly(diff, index, curr_a->coeff + curr_b->coeff, curr_a->power);
			index++;
			curr_a = curr_a->next;
			curr_b = curr_b->next;
		}
	}

	while (curr_a->next || curr_b->next) {
		if(curr_a->next){
			insert_poly(diff, index, curr_a->coeff, curr_a->power);
			index++;
			curr_a = curr_a->next;
		} 
		
		if (curr_b->next) {
			insert_poly(diff, index, curr_b->coeff, curr_b->power);
			index++;
			curr_b = curr_b->next;
		}		
	}
	
	return diff;
}

node *multiply(node *a, node *b) {
	node *curr_a = a;
	node *curr_b = b;

	int index = 1;
	node *prod = create_poly(0, 0);

	while (curr_a != NULL) {
		while (curr_b != NULL) {

			insert_poly(prod, index, (curr_a->coeff) * (curr_b->coeff), (curr_a->power) + (curr_b->power));
			index++;

			curr_b = curr_b->next;
		}

		curr_a = curr_a->next;
		curr_b = b;
	}

	return prod;
}

void element_mul(node *head, int c, int p) {
	node *curr = head;

	while (curr != NULL) {
		curr->coeff *= c;
		curr->power += p;
		curr = curr->next;
	}
}

int main() {
	node *a = create_poly(10, 3);

	insert_poly(a, 1, 5, 2);
	insert_poly(a, 2, 13, 1);
	insert_poly(a, 3, 6, 0);

	node *b = create_poly(16, 4);

	insert_poly(b, 1, 15, 2);
	insert_poly(b, 2, 33, 1);
	insert_poly(b, 3, 4, 0);

	print(a);
	print(b);

	node *s = add_ploy(a, b);
	printf("Sum is: ");
	print(s);

	node *d = sub_ploy(a, b);
	printf("Difference is: ");
	print(d);

	node *m = multiply(a, b);
	printf("Multiplying a and b: ");
	print(m);

	element_mul(b, 10, 2);
	printf("Multiplying b with 10x^2: ");
	print(b);

	return 0;
}