#include <stdio.h>

typedef struct Point2D {
	int x, y;
} Point2D;

int main() {
	Point2D p;
	Point2D *poi;
	
	p.x = 12;
	p.y = 34;

	printf("p.x=%d, p.y=%d\n", p.x, p.y);
	poi = &p;
	
	// 構造体のポインタ変数からのメンバアクセスには
	// -> 演算子を使う
	printf("poi->x=%d, poi->y=%d\n", poi->x, poi->y);
}