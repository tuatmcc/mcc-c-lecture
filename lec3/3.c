#include <stdio.h>
#include <stdlib.h>

int main() {
	int n; // 配列の要素数
	int *arr; // 動的配列を割り当てるためのポインタ変数

	scanf("%d", &n); // ユーザーからの入力を受け取る
	arr = malloc(sizeof(int) * n);
}