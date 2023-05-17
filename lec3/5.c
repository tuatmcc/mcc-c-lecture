#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arr = (int *)malloc(sizeof(int) * 3);
	arr[0] = 12;
	arr[1] = 34;
	arr[2] = 56;
	for (int i = 0; i < 3; ++i) {
		printf("%d\n", arr[i]);
	}
	free(arr);
}