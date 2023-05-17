#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arr = (int *)malloc(sizeof(int)*3);
	arr[0] = 12;
	arr[1] = 34;
	arr[2] = 56;
	free(arr);
	// ↑で解放済みなのに↓で参照してしまった！
	printf("%d\n", arr[0]);
}