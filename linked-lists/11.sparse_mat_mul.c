// Element wise multiply

#include "sparse_matrix.h"

node_sparse_matrix *multiply(node_sparse_matrix *a, node_sparse_matrix *b, int rows, int columns) {
	node_sparse_matrix *result = malloc(sizeof(node_sparse_matrix));
	int index = 0;

	

	return result;
}

int main() {
	node_sparse_matrix *h = create_sparse_matrix(0, 0, 10);
	insert_sparse_matrix(h, 1, 2, 12, 1);
	insert_sparse_matrix(h, 2, 2, 32, 2);
	insert_sparse_matrix(h, 3, 2, 142, 3);
	insert_sparse_matrix(h, 4, 2, 52, 4);

	print_sparse_matrix(h, 5, 5);

	node_sparse_matrix *j = create_sparse_matrix(0, 0, 10);
	insert_sparse_matrix(j, 1, 2, 12, 1);
	insert_sparse_matrix(j, 2, 2, 32, 2);
	insert_sparse_matrix(j, 4, 3, 142, 3);
	insert_sparse_matrix(j, 4, 2, 52, 4);

	puts("\n");
	print_sparse_matrix(j, 5, 5);

	puts("\nSum is: ");
	node_sparse_matrix *mul = multiply(h, j, 5, 5);
	print_sparse_matrix(mul, 5, 5);

	return 0;
}