#include <stdio.h>
typedef struct Point2d {
	int x, y;
} Point2D ;

int main() {
	Point2D p;
	p.x = 0;
	p.y = 1;
	printf("p.x=%d, p.y=%d\n", p.x, p.y);
}