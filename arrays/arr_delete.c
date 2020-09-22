#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	printf("Enter no.of integers:");
	scanf("%d", &n);
	int a[n], i, j, temp1, temp2, p, val;
	
	for (i = 0; i < n; i++) {
		a[i] = rand() % 101;
	}

	for (i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}

	printf("\nEnter position to be deleted:");
	scanf("%d", &p);

	for (i = p; i < n-1; i++) {
		a[i] = a[i + 1];
	}
	printf("\nFinal array:\n");
	
	for (i = 0; i < n-1; i++) {
		printf("%d  ", a[i]);
	}
	
	return 0;
}