#include "sparse_matrix.h"

node_sparse_matrix *add(node_sparse_matrix *a, node_sparse_matrix *b, int rows, int columns) {
	node_sparse_matrix *result = malloc(sizeof(node_sparse_matrix));
	int index = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			node_sparse_matrix *a_curr = a;
			node_sparse_matrix *b_curr = b;

			while (a_curr != NULL) {
				if ((a_curr->row == i) && (a_curr->col == j)) {
					break;
				}
				a_curr = a_curr->next;
			}

			while (b_curr != NULL) {
				if ((b_curr->row == i) && (b_curr->col == j)) {
					break;
				}
				b_curr = b_curr->next;
			}

			if (a_curr && b_curr) {
				if (index == 0) {
					result->row = i;
					result->col = j;
					result->val = a_curr->val + b_curr->val;
				} else {
					insert_sparse_matrix(result, i, j, a_curr->val + b_curr->val, index);
				}

				index++;
			} else {
				if (a_curr) {

					if (index == 0) {
						result->row = i;
						result->col = j;
						result->val = a_curr->val;
					} else {
						insert_sparse_matrix(result, i, j, a_curr->val, index);
					}

					index++;
				} else if (b_curr) {

					if (index == 0) {
						result->row = i;
						result->col = j;
						result->val = b_curr->val;
					} else {
						insert_sparse_matrix(result, i, j, b_curr->val, index);
					}

					index++;
				}
			}
		}
	}

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
	node_sparse_matrix *sum = add(h, j, 5, 5);
	print_sparse_matrix(sum, 5, 5);

	return 0;
}