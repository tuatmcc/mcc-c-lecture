#include <stdio.h>

struct Point2D {
	int x, y;
};

int main() {
	struct Point2D p;
	p.x = 1;
	p.y = 2;
	printf("p.x=%d, p.y=%d\n", p.x, p.y);
}