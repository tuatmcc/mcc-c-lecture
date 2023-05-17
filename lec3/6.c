#include <stdlib.h>

int main() {
	int *arr = (int *)malloc(sizeof(int) * 3);
	free(arr);
	// 実行時にエラー発生
	// free(): double free detected in tcache 2
	// Aborted
	free(arr);
}