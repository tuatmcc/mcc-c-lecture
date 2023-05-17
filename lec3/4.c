#include <stdlib.h>

int main() {
	int *arr = (int *)malloc(3); // int型3要素の配列を定義しようとした
	// int *arr = (int *)malloc(sizeof(int) * 3); 正しくはこう
	arr[0] = 12;
	arr[1] = 34;
	arr[2] = 56;
	// このデモでは発生しないが、意図しないメモリの値を書き換えてしまっている！
}