#include <stdio.h>
#include <stdlib.h>

typedef struct Point2D {
	int x, y;
} Point2D;


int main() {
	Point2D *p = (Point2D *)malloc(sizeof(Point2D) * 1);
	(*p).x = 12;
	printf("%d\n", (*p).x);
	p->x = 34;
	printf("%d\n", p->x);
	free(p);
}