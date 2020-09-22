#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_S {
	struct NODE_S *next;
	int row;
	int col;
	int val;
} node_sparse_matrix;

node_sparse_matrix *create_sparse_matrix(int r, int c, int v);
void print_sparse_matrix(node_sparse_matrix *head, int r, int c);
void insert_sparse_matrix(node_sparse_matrix *head, int r, int c, int v, int index);

node_sparse_matrix *create_sparse_matrix(int r, int c, int v) {
	node_sparse_matrix *head = (node_sparse_matrix *)malloc(sizeof(node_sparse_matrix));

	head->row = r;
	head->col = c;
	head->val = v;
	head->next = NULL;

	return head;
}

void print_sparse_matrix(node_sparse_matrix *head, int r, int c) {
	node_sparse_matrix *curr = head;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			bool found = false;

			while (curr != NULL) { // because we dont know if the LL is sorted or not
				if ((i == curr->row) && (j == curr->col)) {
					printf("%d ", curr->val);
					found = true;
					break;
				}

				curr = curr->next;
			}

			if(!found)
				printf("0 ");

			curr = head;
		}

		printf("\n");
	}
}

void insert_sparse_matrix(node_sparse_matrix *head, int r, int c, int v, int index) {
	int i = 0;
	node_sparse_matrix *curr = head;

	while (i != index - 1) {
		curr = curr->next;
		i++;
	}

	node_sparse_matrix *n = (node_sparse_matrix *)malloc(sizeof(node_sparse_matrix));
	n->next = curr->next;
	n->row = r;
	n->col = c;
	n->val = v;

	curr->next = n;
}