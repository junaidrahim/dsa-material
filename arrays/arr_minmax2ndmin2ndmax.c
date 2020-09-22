#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	printf("Enter no.of integers:");
	scanf("%d", &n);
	int a[n], i, max, min, smax, smin;

	for (i = 0; i < n; i++) {
		a[i] = rand() % 101;
		// scanf("%d",&a[i]);
	}

	for (i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}

	max = a[0];

	for (i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}

	min = a[0];

	for (i = 0; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}

	smax = a[0];

	for (i = 0; i < n; i++) {
		if ((a[i] > smax) && (a[i] < max)) {
			smax = a[i];
		}
	}

	smin = a[0];

	for (i = 0; i < n; i++) {
		if ((a[i] < smin) && (a[i] > min)) {
			smin = a[i];
		}
	}

	printf("\nMaximum value:%d\nMinimum value:%d\n", max, min);
	printf("\nSecond Maximum value:%d\nSecond Minimum value:%d\n", smax, smin);

	return 0;
}